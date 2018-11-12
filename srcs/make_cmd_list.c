/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:40:26 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/07 18:40:31 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	one_arg_ind(t_args *arg, t_cmd *c, char *p)
{
	if (*p == ':')
		write_arg_label1(p + 1, c, arg, 1);
	else if (*(p + 1) != ':')
	{
		if (!g_optab[c->number].args.arg1[1])
			error(12);
		arg->ar_n = ft_atoi(p + 1);
		arg->size = g_optab[c->number].l_size;
		arg->label = NULL;
	}
	else
		write_arg_label1(p + 2, c, arg, 0);
}

void	write_one_arg(char *ptr, t_cmd *c)
{
	t_args *arg;

	arg = (t_args *)malloc(sizeof(t_args));
	arg->number = 1;
	arg->next = NULL;
	c->args = arg;
	ptr = ptr + ft_strlen(g_optab[c->number].c_name);
	while (*ptr == ' ' || *ptr == '\t')
	 	ptr++;
	if (*ptr == '-' || ft_isdigit(*ptr))
	{
		if (!g_optab[c->number].args.arg1[1])
			error(12);
		arg->ar_n = ft_atoi(ptr);
		arg->size = 2;
	}
	else if (*ptr == 'r')
	{
		if (!g_optab[c->number].args.arg1[0])
			error(12);
		arg->ar_n = ft_atoi(ptr + 1);
		arg->size = 1;
	}
	else if (*ptr == '%' || *ptr == ':')
		one_arg_ind(arg, c, ptr);
}

void	validate_command(t_c *p, t_cmd *c, int j, int k) /////////////////////////?????
{
	char	*ptr;
	char	**string;
	int		i;

	i = 0;
	p->counter = 0;
	ptr = ft_strstr(p->line, g_optab[c->number].c_name);
	if (p->checker2 == 42)
	{
		while (ptr[k] != ':')
			k++;
		ptr = ft_strstr(ptr + k, g_optab[c->number].c_name);
	}
	if (!comma_existing(p, 0))
	{
		write_one_arg(ptr, c);
		return ;
	}
	count_comma(p, j);
	ptr = ptr + ft_strlen(g_optab[c->number].c_name);
	while (*ptr == ' ' || *ptr == '\t')
	 	ptr++;
	string = ft_strsplit(ptr, ',');
	start_search_signs(p, string, i, c);
}

void	write_label_str(t_c *p, t_cmd *c, t_label *new, int i)
{
	int j;

	j = i;
	while (p->line[j] != ':')
		j++;
	new->label = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (p->line[i] != ':')
	{
		if (ft_isalnum(p->line[i]) || p->line[i] == '_')
			new->label[j] = p->line[i];
		else
			error(10);
		i++;
		j++;
	}
	new->label[j] = '\0';
	if (p->tmp)
	{
		c->label = p->tmp;
		p->tmp = NULL;
	}
	else
		c->label = new;
	//ft_printf("c->label === %s\n", c->label->label);
}

void	write_label(t_c *p, t_cmd *c)
{
	int		i;
	t_label *new;
	t_label *tmp2;

	i = 0;
	while (p->line[i] == ' ' || p->line[i] == '\t')
		i++;
	if (!p->tmp)
	{
		new = (t_label *)malloc(sizeof(t_label));
		new->next = NULL;
		write_label_str(p, c, new, i);
	}
	else
	{
		tmp2 = p->tmp;
		while (tmp2->next)
			tmp2 = tmp2->next;
		new = (t_label *)malloc(sizeof(t_label));
		new->next = NULL;
		tmp2->next = new;
		write_label_str(p, c, new, i);
	}
}
