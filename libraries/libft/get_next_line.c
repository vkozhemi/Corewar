/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:20:51 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/07 16:36:18 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strccpy(char *str)
{
	size_t	len;
	char	*rat;

	len = 0;
	while (str[len] != '\n')
		len++;
	if ((rat = ft_strnew(len + 1)))
		ft_strncpy(rat, str, len);
	return (rat);
}

static int		ft_nline(char **buff, char **line, char **o_o)
{
	char *liberator;
	char *sidekick;

	liberator = *o_o;
	if (ft_count_c(*buff, '\n'))
	{
		if (!(sidekick = ft_strccpy(*buff)))
			return (-1);
		if (!(*o_o = ft_strjoin(*o_o, sidekick)))
			return (-1);
		ft_strdel(&liberator);
		ft_strdel(&sidekick);
		sidekick = *buff;
		*buff = ft_strchr(*buff, '\n');
		if (!(*buff = ft_strdup(++(*buff))))
			return (-1);
		ft_strdel(&sidekick);
		*line = *o_o;
		return (1);
	}
	if (!(*o_o = ft_strjoin(*o_o, *buff)))
		return (-1);
	ft_strdel(buff);
	ft_strdel(&liberator);
	return (0);
}

static t_gnl		*ft_multi_desu(const int fd, t_gnl *file)
{
	t_gnl		*new;

	if (!file->buff)
	{
		file->buff = NULL;
		file->f_desu = fd;
		file->next = NULL;
	}
	while (file)
	{
		if (file->f_desu == fd)
			return (file);
		if (file->next == NULL)
		{
			if (!(new = (void *)malloc(sizeof(t_gnl))))
				return (NULL);
			file->next = new;
			new->buff = NULL;
			new->f_desu = fd;
			new->next = NULL;
		}
		file = file->next;
	}
	return (file);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	file_mem;
	t_gnl			*f;
	char			*o_o;
	int				check;

	f = &file_mem;
	if (fd < 0 || !line)
		return (-1);
	if (!(f = ft_multi_desu(fd, f)))
		return (-1);
	(o_o) = ft_strnew(1);
	if (f->buff && (check = ft_nline(&f->buff, line, &(o_o))))
		return (check);
	while ((read(fd, f->buff = ft_strnew(BUFF_SIZE), BUFF_SIZE)) > 0)
	{
		if ((check = ft_nline(&f->buff, line, &(o_o))))
			return (check);
	}
	if (ft_strlen(o_o))
	{
		*line = (o_o);
		return (1);
	}
	ft_strdel(&(o_o));
	return (read(fd, NULL, BUFF_SIZE));
}
