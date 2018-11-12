/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_couple_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:58:52 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/08 10:58:54 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	write_arg_label1(char *s, t_cmd *c, t_args *t, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	if (i == 0 && !g_optab[c->number].args.arg1[1])
		error(12);
	if (i == 1 && !g_optab[c->number].args.arg1[2])
		error(12);
	while (ft_isalnum(s[j]) || s[j] == '_')
		j++;
	t->label = (char *)malloc(sizeof(char) * j);
	while (s[j] && s[j] != '#' && s[j] != ';')
	{
		if (s[j] != ' ' && s[j] != '\t')
			error(13);
		j++;
	}
	j = 0;
	while (ft_isalnum(s[j]) || s[j] == '_')
		t->label[k++] = s[j++];
	t->label[k] = '\0';
	// ft_printf("t->label == %s\n", t->label);
	t->size = (i == 0) ? g_optab[c->number].l_size : 2;
	// ft_printf("cmd size = %d\n", t->size);
}

void	check_t_reg(char **string, int i, t_cmd *c, t_args *t)
{
	char *p;

	p = string[i];
	if (i == 0)
		if (!g_optab[c->number].args.arg1[0])
			error(12);
	if (i == 1)
		if (!g_optab[c->number].args.arg2[0])
			error(12);
	if (i == 2)
		if (!g_optab[c->number].args.arg3[0])
			error(12);
	t->ar_n = ft_atoi(p + 1 + c->char_c);
	t->size = 1;
}

void	check_t_dir(char **string, int i, t_cmd *c, t_args *t)
{
	char *p;

	p = string[i];
	if (i == 0)
		if (!g_optab[c->number].args.arg1[1])
			error(12);
	if (i == 1)
		if (!g_optab[c->number].args.arg2[1])
			error(12);
	if (i == 2)
		if (!g_optab[c->number].args.arg3[1])
			error(12);
	// ft_printf(" char = %c\n", string[i][c->char_c + 1]);
	if (string[i][c->char_c + 1] == ':')
	{
		write_arg_label(string[i], 0, c, t);
		return ;
	}
	else
		t->ar_n = ft_atoi(p + 1 + c->char_c);
	t->size = g_optab[c->number].l_size;
	// ft_printf("t->ar_n == %d\n", t->ar_n);
}

void	check_arg(char **string, int i, t_cmd *c, int k)
{
	t_args *arg;
	t_args *tmp;

	if (i > 2)
		error(12);
	if (i == 0)
	{
		arg = (t_args *)malloc(sizeof(t_args));
		arg->number = 1;
		arg->size = 0;
		arg->next = NULL;
		arg->label = NULL;
		c->args = arg;
	}
	else
		make_new_argument(c->args);
	tmp = c->args;
	while (tmp->next)
		tmp = tmp->next;
	if (k == 1)
		check_t_dir(string, i, c, tmp);
	else if (k == 2)
		check_t_reg(string, i, c, tmp);
	else if (k == 3)
		check_t_ind(string, i, c, tmp);
}

void	start_search_signs(t_c *p, char **string, int i, t_cmd *c)
{
	int 	l;
	t_args	*temp;

	while (string[i])
	{
		l = 0;
		while (string[i][l] == ' ' || string[i][l] == '\t')
			l++;
		c->char_c = l;
		if (string[i][l] == '%')
			check_arg(string, i, c, 1);
		else if (string[i][l] == 'r')
			check_arg(string, i, c, 2);
		else if (ft_isdigit(string[i][l]) || string[i][l] == '-'
			|| string[i][l] == ':')
			check_arg(string, i, c, 3);
		else
		{
			printf("%s\n", string[i]);
			error(11);
		}
		i++;
	}
	temp = c->args;
	while (temp->next)
		temp = temp->next;
	if ((i - 1) != p->counter)
		error2(14);
}
