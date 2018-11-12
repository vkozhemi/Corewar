/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:15:39 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/09 12:15:41 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

int		comma_existing(t_c *p, int i)
{
	while (p->line[i])
	{
		if (p->line[i] == '#' || p->line[i] == ';')
		{
			p->line[i] = '\0';
			break ;
		}
		if (p->line[i] == ',')
		{
			while (p->line[++i])
			{
				if (p->line[i] == '#' || p->line[i] == ';')
				{
					p->line[i] = '\0';
					break ;
				}
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	reverse(int fd, unsigned char *n, int count)
{
	while (count--)
		write(fd, n + count, 1);
}

void	writting_coomand(t_c *file, int fd)
{
	t_cmd	*lst;

	lst = file->cmd_p;
	while (lst)
	{
		lst->number++;
		write(fd, &lst->number, 1);
		(lst->number != 1 && lst->number != 9 && lst->number != 12 && lst->number != 15) ? reverse(fd, (unsigned char*)&lst->codage, 1) : 0;
		while (lst->args)
		{
			(lst->args->size) ? reverse(fd, (unsigned char*)&lst->args->ar_n, lst->args->size) : 0;
			lst->args = lst->args->next;
		}
		lst = lst->next;
	}
}

int		file_creator(t_c *file)
{
	int				fd;
	unsigned int	magic;
	t_cmd			*lst_tmp;
	
	lst_tmp = file->cmd_p;
	file->size = 0;
	while (lst_tmp)
	{
		file->size += lst_tmp->cmd_s;
		lst_tmp = lst_tmp->next;
	}
	magic = COREWAR_EXEC_MAGIC;
	fd = open(file->f_name, O_WRONLY | O_CREAT, 0644);
	reverse(fd, (unsigned char*)&magic, 4);
	write(fd, &file->player_n, PROG_NAME_LENGTH);
	magic = 0;
	write(fd, &magic, 4);
	reverse(fd, (unsigned char*)&file->size, 4);
	write(fd, &file->comment, COMMENT_LENGTH);
	write(fd, &magic, 4);
	writting_coomand(file, fd);
	close(fd);
	return (1);
}
