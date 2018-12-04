/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:30:28 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/19 18:30:30 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static unsigned int	vm_strtouint(unsigned char *str)
{
	unsigned int ret;

	ret = *str++ << 24;
	ret += *str++ << 16;
	ret += *str++ << 8;
	ret += *str;
	return (ret);
}

static void			vm_show_player(t_player *player)
{
	ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		player->number,
		player->size,
		player->name,
		player->comment);
}

static void			vm_sread(int fd, char *container, int size, char *error)
{
	if (read(fd, container, size) != size)
		ft_error(error);
}

static int			vm_check_file(char *name)
{
	int		fd;
	char	*tmp;

	if (!name)
		ft_error("no file name");
	if (!(tmp = ft_strstr(name, ".cor")))
		ft_error("file is not .cor");
	if (tmp[4])
		ft_error("bad file name");
	if ((fd = open(name, O_RDONLY)) < 1)
		ft_error("no such file");
	return (fd);
}

t_player			*vm_readfile(char *str, int number)
{
	t_player		*player;
	int				fd;
	char			buff[4];

	fd = vm_check_file(str);
	player = vm_list_player_new(number);
	vm_sread(fd, buff, 4, "invalid magic bin");
	if (vm_strtouint((UC *)buff) != COREWAR_EXEC_MAGIC)
		ft_error("file is not magic");
	vm_sread(fd, player->name, PROG_NAME_LENGTH + 4, "invalid name bin");
	vm_sread(fd, buff, 4, "invalid size bin");
	player->size = vm_strtouint((UC *)buff);
	if (player->size > CHAMP_MAX_SIZE)
		ft_error("player is too big");
	vm_sread(fd, player->comment, COMMENT_LENGTH + 4, "invalid comment bin");
	if (!(player->code = (UC *)malloc(sizeof(UC) * player->size)))
		ft_error("coudn't allocate memory");
	read(fd, player->code, player->size);
	close(fd);
	vm_show_player(player);
	return (player);
}
