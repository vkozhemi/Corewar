/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:08:20 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/08 11:08:22 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	write_arg_label(char *string, int i, t_cmd *c, t_args *t)
{
	int j;
	int k;

	k = 0;
	j = c->char_c;
	j += (i != 0) ? 1 : 2;
	while (ft_isalnum(string[j]) || string[j] == '_')
		j++;
	t->label = (char *)malloc(sizeof(char) * j);
	while (string[j] && string[j] != '#' && string[j] != ';')
	{
		if (string[j] != ' ' && string[j] != '\t')
			error2(13);
		j++;
	}
	j = c->char_c;
	j += (i != 0) ? 1 : 2;
	while (ft_isalnum(string[j]) || string[j] == '_')
		t->label[k++] = string[j++];
	t->label[k] = '\0';
	t->size = (i == 0) ? g_optab[c->number].l_size : 2;
}

void	make_new_argument(t_args *arg)
{
	t_args *new;
	t_args *temp;

	temp = arg;
	new = (t_args *)malloc(sizeof(t_args));
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
	new->label = NULL;
	new->size = 0;
	new->number = temp->number + 1;
}

void	check_t_ind(char **string, int i, t_cmd *c, t_args *t)
{
	if (i == 0)
		if (!g_optab[c->number].args.arg1[2])
			error2(12);
	if (i == 1)
		if (!g_optab[c->number].args.arg2[2])
			error2(12);
	if (i == 2)
		if (!g_optab[c->number].args.arg3[2])
			error2(12);
	if (string[i][c->char_c] == ':')
	{
		write_arg_label(string[i], 1, c, t);
		return ;
	}
	t->ar_n = ft_atoi(string[i]);
	t->size = 2;
}

void	error2(int i)
{
	if (i == 12)
		ft_printf("%s\n", "Wrong argument");
	else if (i == 13)
		ft_printf("%s\n", "Wrong label string");
	else if (i == 14)
		ft_printf("%s\n", "Error too much or too less comma in string");
	else if (i == 15)
		ft_printf("%s\n", "Error: no such label");
	else if (i == 16)
		ft_printf("%s\n", "Too many names or comments in file");
	else if (i == 17)
		ft_printf("%s\n", "Wrong string with name");
	else if (i == 18)
		ft_printf("%s\n", "Wrong label in argument");
	else if (i == 19)
		ft_printf("%s\n", "Too much or too less arguments");
	else if (i == 20)
		ft_printf("%s\n", "Expected [\"]");
	else if (i == 21)
		ft_printf("%s\n", "Syntax error at token [TOKEN][005:001] ENDLINE");
	else if (i == 22)
		ft_printf("%s\n", "No command");
	exit(0);
}

void	new_function(t_c *p)
{
	t_cmd			*point;
	unsigned int	temp;

	point = p->cmd_p;
	temp = 0;
	if (!point)
		error2(22);
	while (point)
	{
		point->size_before = temp;
		temp += point->cmd_s;
		point = point->next;
	}
	find_label_instruct(p);
}
