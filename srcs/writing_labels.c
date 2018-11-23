/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:19:39 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/07 15:19:42 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

t_cmd	*make_new_cmd(t_c *p)
{
	t_cmd *new;
	t_cmd *tmp;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	tmp = p->cmd_p;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	new->label = NULL;
	new->args = NULL;
	return (new);
}

void	make_label(t_c *p)
{
	t_label *new;
	t_label *tmp;

	tmp = p->tmp;
	new = (t_label *)malloc(sizeof(t_label));
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	new->label = NULL;
}

void	check_label(t_c *p, t_cmd *c, int i)
{
	t_cmd	*temp;
	int		k;

	k = 0;
	if (p->cmd_p->cmd_s != -42)
		c = make_new_cmd(p);
	temp = p->cmd_p;
	while (temp->next)
		temp = temp->next;
	if ((ft_strchr(p->line, ':')))
	{
		if (label_checker(p, i))
			write_label(p, c);
	}
	if (p->tmp)
	{
		c->label = p->tmp;
		p->tmp = NULL;
	}
	c->number = i;
	p->counter = 0;
	validate_command(p, c, -1, k);
	calc_codage(p, c, 0, 0);
}

int		is_str_label(t_c *p)
{
	int i;

	i = 0;
	while (p->line[i] != ':')
	{
		if (p->line[i] != '\t' && p->line[i] != ' ' && !ft_isalnum(p->line[i])
			&& p->line[i] != '_')
			return (0);
		i++;
	}
	i++;
	while (p->line[i])
	{
		if (p->line[i] != '\t' && p->line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	start_label(t_c *p, int k)
{
	t_label *l;
	t_label *tp;
	int		i;

	i = 0;
	if (!is_str_label(p))
		error(9);
	if (!p->tmp)
	{
		l = (t_label *)malloc(sizeof(t_label));
		l->next = NULL;
		p->tmp = l;
	}
	else
		make_label(p);
	tp = p->tmp;
	while (tp->next)
		tp = tp->next;
	while (!ft_isalnum(p->line[i]))
		i++;
	while (p->line[k] != ':')
		k++;
	k -= i;
	tp->label = ft_strsub(p->line, i, k);
}
