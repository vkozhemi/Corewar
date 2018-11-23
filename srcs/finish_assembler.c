/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_assembler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:24:52 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/15 19:24:54 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	skip(t_c *p, int *i, int *label)
{
	char *c;

	c = 0;
	while (!ft_strchr("%r, \t", p->line[*i]) &&
		(ft_isalnum(p->line[*i]) || p->line[*i] == ':' || p->line[*i] == '_'))
	{
		if (ft_isalpha(p->line[*i]))
			*label = 1;
		if (*label && p->line[*i] == ':')
			(*label)--;
		if (p->line[*i] == '_' && !(*label) && !ft_isalpha(p->line[*i - 1]))
			error2(12);
		(*i)--;
	}
}

void	check_cmd_args(t_c *p)
{
	t_cmd	*cmd;
	t_args	*arg;

	cmd = p->cmd_p;
	while (cmd)
	{
		arg = cmd->args;
		while (arg->next)
		{
			if (arg->type == 1 && arg->ar_n >= 100)
				error2(19);
			arg = arg->next;
		}
		if (arg->type == 1 && arg->ar_n >= 100)
			error2(19);
		if (arg->number != g_optab[cmd->number].n_arg)
			error2(19);
		cmd = cmd->next;
	}
}

void	check_cm_instring(t_c *p, int i)
{
	int checker;

	checker = 0;
	while (p->line[++i])
	{
		if (p->line[i] == '%' && (p->line[i + 1] == ':'
			|| p->line[i + 1] == '-'))
		{
			i++;
			checker++;
		}
		else if (p->line[i] == ':' || p->line[i] == '%')
			checker++;
		else if (p->line[i] == 'r' && (ft_isdigit(p->line[i + 1])))
			checker++;
		else if (p->line[i] == ',' && ft_isdigit(p->line[i + 1]))
			checker++;
		else if (p->line[i] == '-' && ft_isdigit(p->line[i + 1]))
			checker++;
		else if ((p->line[i] == ' ' || p->line[i] == '\t')
			&& (ft_isdigit(p->line[i + 1])))
			checker++;
	}
	if (checker > 2)
		error2(14);
}

void	validate_name(t_c *p, int i)
{
	char flag;

	flag = 0;
	i += 5;
	while (p->file[i] && (p->file[i] == ' ' || p->file[i] == '\t'))
		i++;
	if (p->file[i] && p->file[i] != '\"')
		error2(17);
	while (p->file[++i])
	{
		if (p->file[i] == '\"' && ++flag)
			break ;
		if (p->file[i] == '.' && p->file[i + 1] == 'c' &&
			p->file[i + 2] == 'o' && p->file[i + 3] == 'm'
			&& p->file[i + 4] == 'm' && p->file[i + 5] == 'e'
			&& p->file[i + 6] == 'n' && p->file[i + 7] == 't')
			break ;
	}
	if (p->file[i] == '\"')
		while (!ft_strchr("\n;#", p->file[++i]))
			if (!ft_strchr("\t ", p->file[i]))
				error2(17);
	if (!flag)
		error(9);
}

int		count_commands(char *p)
{
	int i;
	int checker;

	i = -1;
	checker = 0;
	while (p[++i])
	{
		if (p[i] == '%' && (p[i + 1] == ':' || p[i + 1] == '-'))
		{
			i++;
			checker++;
		}
		else if (p[i] == ':' || p[i] == '%')
			checker++;
		else if (p[i] == 'r' && (ft_isdigit(p[i + 1])))
			checker++;
		else if ((p[i] == ' ' || p[i] == '\t')
			&& (ft_isdigit(p[i + 1])))
			checker++;
		else if (p[i] == ',' && ft_isdigit(p[i + 1]))
			checker++;
		else if (p[i] == '-' && ft_isdigit(p[i + 1]))
			checker++;
	}
	return (checker);
}
