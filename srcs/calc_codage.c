/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_codage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <vkozhemi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:43:57 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/11/23 15:44:00 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	calc_codage_2(t_c *p, t_cmd *c, int *i, int j)
{
	if (p->line[*i] == '%' && (c->cmd_s += g_optab[c->number].l_size))
	{
		c->codage >>= 2;
		c->codage += 128;
		while (p->line[*i] != ',' && *i >= 0)
			(*i)--;
		write_type(c, j, 2);
	}
	else if (p->line[*i] == 'r' && ++c->cmd_s)
	{
		c->codage >>= 2;
		c->codage += 64;
		while (p->line[*i] != ',' && *i >= 0)
			(*i)--;
		write_type(c, j, 1);
	}
	else if (p->line[*i] == ',' || p->line[*i] == ' ' || p->line[*i] == '\t')
	{
		c->codage >>= 2;
		c->cmd_s += 2;
		c->codage += 192;
		while (p->line[*i] != ',' && *i >= 0)
			(*i)--;
		write_type(c, j, 3);
	}
}

void	calc_codage(t_c *p, t_cmd *c, int i, int j)
{
	int label;

	label = 0;
	c->codage = 0;
	c->cmd_s = 1;
	while (p->line[i] && p->line[i] != '#' && p->line[i] != ';')
		i++;
	i--;
	c->cmd_s += g_optab[c->number].codage;
	while (i >= 0)
	{
		while (i >= 0 && (p->line[i] == ' ' || p->line[i] == '\t'))
			i--;
		skip(p, &i, &label);
		while (p->line[i] == 'r' && !ft_strchr(", \t", p->line[i - 1]) && i--)
			skip(p, &i, &label);
		if (p->line[i] == '-')
			i--;
		if (label || !ft_strchr("%r, \t", p->line[i]))
			error2(12);
		calc_codage_2(p, c, &i, j++);
		i--;
	}
}

int		is_comment(t_c *p, int i)
{
	while (i != -1)
	{
		if (p->file[i] == '\n')
			break ;
		if (p->file[i] == '#' || p->file[i] == ';')
			return (0);
		i--;
	}
	return (1);
}
