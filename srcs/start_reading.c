/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <vkozhemi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:37:12 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/11/23 15:37:16 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	check_next_comment_line(t_c *p, char *ptr, int *i)
{
	int gnl;

	if (ptr[(*i)++] != '\"')
	{
		free(p->line);
		while ((gnl = get_next_line(p->fd, &(p->line))) > 0)
		{
			if (p->line && (p->c = ft_strchr(p->line, '\"')))
			{
				ptr = ft_strchr(p->line, '\"');
				*i = 1;
				break ;
			}
			free(p->line);
		}
		if (gnl == 0)
			error2(20);
	}
	while (ptr[*i] && ptr[*i] != ';' && ptr[*i] != '#')
	{
		if (ptr[*i] != '\t' && ptr[*i] != ' ')
			error2(20);
		(*i)++;
	}
}

void	check_if_finish(t_c *p, char *ptr, int comment)
{
	int				i;
	static int		lm = 0;

	if (++lm > 2)
		error2(16);
	i = 0;
	while (p->line + i != ptr)
	{
		if (p->line[i] != ' ' && p->line[i] != '\t')
			error(8);
		i++;
	}
	i = (comment == 1) ? 8 : 5;
	while (ptr[i] == ' ' || ptr[i] == '\t')
		i++;
	if (ptr[i++] != '\"')
		error(8);
	while (ptr[i] && ptr[i] != '\"')
		i++;
	check_next_comment_line(p, ptr, &i);
}

void	reading_map(t_c *p, int i, t_cmd *c)
{
	if (ft_strchr(p->line, '.'))
		if (!check_point(p, 0, 0))
			error(7);
	i = 19;
	while (--i >= -1)
	{
		p->checker2 = 0;
		if (i == -1 && !ft_strchr(p->line, ':'))
			error(6);
		if (i == -1 && ft_strchr(p->line, ':'))
		{
			start_label(p, 0);
			break ;
		}
		if (ft_strstr(p->line, g_optab[i].c_name))
		{
			if ((is_command_nolabel(p, i, 0)))
			{
				read_command(p, i, 0, c);
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

void	start_reading(t_c *p, char *str, t_cmd *cmd)
{
	p->fd = open(str, O_RDONLY);
	if (p->fd < 0)
		error(1);
	while (get_next_line(p->fd, &(p->line)) > 0)
	{
		if (p->line[0] == '#')
			free(p->line);
		else if (strstr(p->line, ".comment"))
			check_if_finish(p, strstr(p->line, ".comment"), 1);
		else if (strstr(p->line, ".name"))
			check_if_finish(p, strstr(p->line, ".name"), 0);
		else if (!ft_strcmp(p->line, ""))
			free(p->line);
		else if (empty_string(p, 0))
			free(p->line);
		else
		{
			put_zero(p);
			reading_map(p, -1, cmd);
			free(p->line);
		}
	}
	new_function(p);
}
