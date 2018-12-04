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

#include "core.h"

void	symbols_before_cmd(t_c *p, char *r, int i)
{
	char	*s;
	int		m;

	m = 0;
	while ((r + 1) && !ft_strchr(" r%\t", *(r + ft_strlen(g_optab[i].c_name))))
		r = ft_strstr(r + 1, g_optab[i].c_name);
	s = ft_strchr(p->line, ':');
	if (r && s && s < r && ++m)
		while (s + m != r)
		{
			if (s[m] != ' ' && s[m] != '\t')
				error(9);
			m++;
		}
	else
		while (p->line + m != r)
		{
			if (p->line[m] != ' ' && p->line[m] != '\t')
				error(9);
			m++;
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
	if (!ft_strchr(" \t%r", *(ptr + ft_strlen(g_optab[i].c_name))))
		return (0);
	ptr = ptr + ft_strlen(g_optab[i].c_name);
	while (ptr[++k])
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
	while (p->line[k] != '.')
		k++;
	if (!ft_strchr(p->line, '#') && !ft_strchr(p->line, ';'))
		return (0);
	while (p->line[c] != '#' && p->line[c] != ';')
		c++;
	if (k < c)
		return (0);
	else
		return (1);
}

void	read_command(t_c *p, int i, int k, t_cmd *cmd)
{
	symbols_before_cmd(p, ft_strstr(p->line, g_optab[i].c_name), i);
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
