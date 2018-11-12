/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_write_infile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:15:14 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/08 13:15:16 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

int		if_not_cmd(char *ptr, t_c *p, int i, int k)
{
	char *p2;

	while (ft_isalnum(ptr[k]) || ptr[k] == '_')
		k++;
	if (ptr[k] == ':')
	{
		p->checker2 = 10;
		if ((p2 = ft_strstr(ptr + k, g_optab[i].c_name)))
		{
			p->checker2 = 42;
			return (1);
		}
	}
	return (0);
}

void	count_comma(t_c *p, int j)
{
	while (p->line[++j])
	{
		if (p->line[j] == ',')
			p->counter++;
		if (p->line[j] == ',' && p->line[j + 1] == ',')
			error(8);
	}
}

void	find_fs(t_c *p, t_cmd *t, t_args *ar, unsigned int r)
{
	t_cmd		*new_c;
	t_label		*tl;

	new_c = p->cmd_p;
	while (new_c)
	{
		tl = new_c->label;
		while (tl)
		{
			if (!ft_strcmp(ar->label, tl->label))
				break ;	
			tl = tl->next;
		}
		if (tl && !ft_strcmp(ar->label, tl->label))
				break ;	
		new_c = new_c->next;
	}
	while (new_c && &new_c != &t)
	{
		r += new_c->cmd_s;
		new_c = new_c->next;
	}
	if (!r)
		error2(15);
	ar->ar_n = r;
	free(ar->label);
	ar->label = NULL;
}

// void	find_this_label(t_c *p, t_cmd *t, t_args *ar)
// {
// 	t_cmd			*temp;
// 	unsigned int	res;
// 	t_label			*tl;
// 	t_args			*tmp_arg;

// 	temp = t->next;
// 	tmp_arg = ar->next;
// 	res = 0;
// 	while (tmp_arg)
// 	{
// 		res += tmp_arg->size;
// 		tmp_arg = tmp_arg->next;
// 	}
// 	while (temp)
// 	{
// 		res += temp->cmd_s;
// 		// if (!ft_strcmp("leon_ecrit", ar->label))
// 			// printf("res = %d cmd = %d  cmd_size = %d\n", res, temp->number, temp->cmd_s);
// 		tl = temp->label;
// 		while (tl)
// 		{
// 			if (!ft_strcmp(ar->label, tl->label))
// 			{
// 				ar->ar_n = res;
// 				free(ar->label);
// 				ar->label = NULL;
// 				return ;
// 			}
// 			tl = tl->next;
// 		}
// 		temp = temp->next;
// 	}
// 	res = 0;
// 	find_fs(p, t, ar, res);
// }

t_cmd	*find_label(t_cmd *t, char *label)
{
	t_cmd			*temp;
	t_label			*tl;

	temp = t;
	// printf("%s\n", label);
	while (temp)
	{
		tl = temp->label;
		// if (!ft_strcmp("beegees_gen", label))
		// 	printf("cmd = %d  cmd_size = %d\n", temp->number, temp->cmd_s);
		while (tl)
		{
			if (!ft_strcmp(label, tl->label))
				return (temp);
			tl = tl->next;
		}
		temp = temp->next;
	}
	return (NULL);
}

void	find_this_label(t_c *p, t_cmd *t, t_args *ar)
{
	t_cmd			*temp;
	unsigned int	res;
	t_label			*tl;

	if (!(temp = find_label(p->cmd_p, ar->label)))
		error2(15);
	res = temp->size_before - t->size_before;
	printf("label = %s. temp->number = %d temp->size_before = %d this->size_before = %d\n", ar->label,temp->number, temp->size_before, t->size_before);
	ar->ar_n = res;
}

void	find_label_instruct(t_c *p)
{
	t_cmd	*temp;
	t_args	*argum;

	temp = p->cmd_p;
	while (temp)
	{
		argum = temp->args;
		while (argum)
		{
			if (argum->label)
				find_this_label(p, temp, argum);
			argum = argum->next;
		}
		temp = temp->next;
	}
}
