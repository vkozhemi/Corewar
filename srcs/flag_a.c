/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:26:05 by msakovyc          #+#    #+#             */
/*   Updated: 2018/11/20 13:26:08 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

int		label_checker(t_c *p, int i)
{
	char	*p1;
	char	*p2;
	int		k;

	k = 0;
	p1 = ft_strchr(p->line, ':');
	p2 = ft_strstr(p->line, g_optab[i].c_name);
	if (p->checker2 == 42)
	{
		while (p2[k] != ':')
			k++;
		p2 = ft_strstr(p2 + k, g_optab[i].c_name);
	}
	if (p1 < p2)
		return (1);
	else
		return (0);
}

void	write_type(t_cmd *c, int j, int type)
{
	t_args	*arg;
	int		counter;

	arg = c->args;
	counter = 0;
	while (arg->next)
	{
		arg = arg->next;
		counter++;
	}
	j = counter - j;
	arg = c->args;
	while (arg && arg->number - 1 != j)
		arg = arg->next;
	if (arg)
		arg->type = type;
}

void	output_first(t_cmd *lst)
{
	t_args	*arg;
	int		width;

	if (lst->label)
		ft_printf("%-11d:    %s:\n", lst->size_before, lst->label->label);
	ft_printf("%-5d(%-3d) :        %-10s", lst->size_before, lst->cmd_s,
		g_optab[lst->number - 1].c_name);
	arg = lst->args;
	while (arg)
	{
		width = 18;
		(arg->type == 1 && width--) ? ft_printf("r") : 0;
		(arg->type == 2 && width--) ? ft_printf("%%") : 0;
		if (arg->label)
			ft_printf(":%-*s", --width, arg->label);
		else
			ft_printf("%-*d", width, arg->ar_n);
		arg = arg->next;
	}
}

void	output_second(t_cmd *lst)
{
	t_args	*arg;

	ft_printf("\n                    %-4d", lst->number);
	if (lst->codage)
		ft_printf("%-6d", lst->codage);
	else
		ft_printf("\t  ", lst->codage);
	arg = lst->args;
	while (arg)
	{
		if (arg->type == 1)
			ft_printf("%-18d", arg->ar_n);
		else if (arg->type == 2 && arg->size == 4)
			ft_printf("%-4d%-4d%-4d%-6d", arg->ar_n / 65536 / 256,
		arg->ar_n / 65536 % 256, arg->ar_n / 256 % 256, arg->ar_n % 256);
		else if (arg->type == 3 || (arg->type == 2 && arg->size == 2))
			ft_printf("%-4d%-14d", arg->ar_n / 256 % 256, arg->ar_n % 256);
		arg = arg->next;
	}
}

void	flag_a(t_c *f)
{
	t_cmd	*lst;
	t_args	*arg;

	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %d bytes\n", f->size);
	ft_printf("Name : \"%s\"\nComment : \"%s\"\n\n", f->player_n, f->comment);
	lst = f->cmd_p;
	while (lst)
	{
		output_first(lst);
		output_second(lst);
		ft_printf("\n                    %-4d", lst->number);
		if (lst->codage)
			ft_printf("%-6d", lst->codage);
		else
			ft_printf("      ", lst->codage);
		arg = lst->args;
		while (arg)
		{
			ft_printf("%-18d", arg->ar_n);
			arg = arg->next;
		}
		ft_printf("\n\n");
		lst = lst->next;
	}
}
