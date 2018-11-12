/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:54:22 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/07 11:54:24 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	check_if_finish(t_c *p)
{
	int i;
	int c;

	i = -1;
	c = 0;
	while (p->line[++i])
		if (p->line[i] == '\"')
			c++;
	if (c == 2)
		free(p->line);
	else
	{
		free(p->line);
		while (get_next_line(p->fd, &(p->line)))
		{
			if ((p->c = ft_strchr(p->line, '\"')))
				break ;
			free(p->line);
		}
	}
}

void	reading_map(t_c *p, int i, t_cmd *c)
{
	char	*ptr;
	char	*p2;

	if ((ptr = ft_strchr(p->line, '.')))
		if (!check_point(p, 0, 0))
			error(7);
	while (++i < 17)
	{
		p->checker2 = 0;
		if (i == 16 && !(p2 = ft_strchr(p->line, ':')))
			error(6);
		if (i == 16 && (p2 = ft_strchr(p->line, ':')))
		{
			start_label(p, 0);
			break ;
		}
		if (ft_strstr(p->line, g_optab[i].c_name))
		{
			if ((is_command_nolabel(p, i, 0)))
			{
				read_command(p, g_optab[i].op_code, 0, c);
				break ;
			}
		}
	}
}

int		empty_string(t_c *p, int i)
{
	int c;

	c = 0;
	while (p->line[i])
	{
		if ((p->line[i] == '#' || p->line[i] == ';') && c == 0)
			return (1);
		if (p->line[i] != ' ' && p->line[i] != '\t')
			c++;
		i++;
	}
	if (!c)
		return (1);
	else
		return (0);
}

void	start_reading(t_c *p, char *str)
{
	t_cmd	*cmd;

	cmd = NULL;
	p->fd = open(str, O_RDONLY);
	if (p->fd < 0)
		error(1);
	while (get_next_line(p->fd, &(p->line)) > 0)
	{
		if (p->line[0] == '#' || strstr(p->line, ".name"))
			free(p->line);
		else if (strstr(p->line, ".comment"))
			check_if_finish(p);
		else if (!ft_strcmp(p->line, ""))
			free(p->line);
		else if (empty_string(p, 0))
			free(p->line);
		else
		{
			reading_map(p, -1, cmd);
			free(p->line);
		}
	}
	new_function(p);
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
