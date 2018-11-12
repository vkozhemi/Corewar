/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:24:08 by vkorniie          #+#    #+#             */
/*   Updated: 2018/05/16 17:29:34 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		reading(char *buf, int fd, t_gnl *list)
{
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = list->str;
		list->str = ft_strjoin(list->str, buf);
		free(tmp);
		if (ft_strchr(list->str, '\n'))
			break ;
	}
	if (!(ft_strchr(list->str, '\n')) && !list->str)
		return (0);
	return (1);
}

int		writting(t_gnl *gnl, char **line)
{
	char *tmp;

	tmp = ft_strchr(gnl->str, '\n');
	if (tmp)
	{
		*line = ft_strsub(gnl->str, 0, tmp - gnl->str);
		tmp = gnl->str;
		gnl->str = ft_strsub(tmp, ft_strchr(tmp, '\n') - tmp + 1,
			ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(gnl->str);
		free(gnl->str);
		gnl->str = 0;
		if (**line)
			return (1);
		return (0);
	}
}

t_gnl	*make_new(t_gnl *gnl, int fd)
{
	t_gnl *new_list;

	new_list = (t_gnl *)malloc(sizeof(t_gnl));
	new_list->str = ft_strnew(0);
	new_list->next = gnl;
	new_list->fd = fd;
	return (new_list);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*gnl = NULL;
	t_gnl			*tmp;
	int				wr;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	tmp = gnl;
	wr = 0;
	while (tmp && fd != tmp->fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		gnl = make_new(gnl, fd);
		tmp = gnl;
	}
	while (wr != 1)
	{
		if (!reading(buf, fd, tmp))
			return (0);
		wr = writting(tmp, line);
	}
	return (1);
}
