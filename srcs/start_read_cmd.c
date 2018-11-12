/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_read_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:40:24 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/07 12:40:27 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	calc_codage_2(t_c *p, t_cmd *c, int *i)
{
	if (p->line[*i] == '%')
	{
		c->codage >>= 2;
		c->cmd_s += g_optab[c->number].l_size;
		c->codage += 128;
		while (p->line[*i] != ',' && *i >= 0)
			(*i)--;
	}
	else if (p->line[*i] == 'r' && ++c->cmd_s)
	{
		c->codage >>= 2;
		c->codage += 64;
		while (p->line[*i] != ',' && *i >= 0)
			(*i)--;
	}
	else if (p->line[*i] == ',' || p->line[*i] == ' ' || p->line[*i] == '\t')
	{
		c->codage >>= 2;
		c->cmd_s += 2;
		c->codage += 192;
		while (p->line[*i] != ',' && *i >= 0)
			(*i)--;
	}
}

void	calc_codage(t_c *p, t_cmd *c)
{
	int i;

	i = 0;
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
		if (ft_isalpha(p->line[i]))
		{
			while (p->line[i] != ':')
				i--;
			i--;
		}
		else if (ft_isdigit(p->line[i]) && (!ft_isalpha(p->line[i - 1]) || p->line[i - 1] == 'r'))
			while (ft_isdigit(p->line[i]) || p->line[i] == '-')
				i--;
		calc_codage_2(p, c, &i);
		i--;
	}
}

int		is_command_nolabel(t_c *p, int i, int k)
{
	char	*ptr;

	k = -1;
	ptr = ft_strstr(p->line, g_optab[i].c_name);
	if ((if_not_cmd(ptr, p, i, 0)))
		return (1);
	if (p->checker2 == 10)
		return (0);
	if (*(ptr + ft_strlen(g_optab[i].c_name)) == '\0'
		|| *(ptr + ft_strlen(g_optab[i].c_name)) == ',')
		return (0);
	if (*(ptr + ft_strlen(g_optab[i].c_name)) != ' '
		&& *(ptr + ft_strlen(g_optab[i].c_name)) != '\t'
		&& *(ptr + ft_strlen(g_optab[i].c_name)) != '%'
		&& *(ptr + ft_strlen(g_optab[i].c_name)) != 'r')
		return (0);
	ptr = ptr + ft_strlen(g_optab[i].c_name);
	while (ptr[++k] )
	{
		if (ptr[k] == '\0' || ptr[k] == ',')
			return (0);
		if (ptr[k] != ' ' && ptr[k] != '\t')
			break ;
	}
	return (1);
}

int		check_point(t_c *p, int k, int c)
{
	char *ptr;
	char *ptr2;

	while (p->line[k] != '.')
		k++;
	if (!(ptr = ft_strchr(p->line, '#')))
		return (0);
	if (!(ptr2 = ft_strchr(p->line, ';')))
		return (0);
	while (p->line[c] != '#' || p->line[c] != ';')
		c++;
	if (k < c)
		return (0);
	else
		return (1);
}

void	read_command(t_c *p, int i, int k, t_cmd *cmd)
{
	if (!p->cmd_p)
	{
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		cmd->cmd_s = -42;
		cmd->next = NULL;
		cmd->label = NULL;
		cmd->args = NULL;
		p->cmd_p = cmd;
	}
	if (p->line[k] == '\t' || p->line[k] == ' ')
	{
		while (p->line[k] == '\t' || p->line[k] == ' ')
			k++;
		if (p->line[k] == '#' || p->line[k] == ';')
			return ;
	}
	check_label(p, cmd, i);
}
