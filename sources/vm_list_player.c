/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_list_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:34:45 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/23 18:34:47 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*vm_list_player_new(int number)
{
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		ft_error("couldn't allocate memory");
	if (!(player->name = ft_strnew(PROG_NAME_LENGTH + 4)))
		ft_error("couldn't allocate memory");
	if (!(player->comment = ft_strnew(COMMENT_LENGTH + 4)))
		ft_error("couldn't allocate memory");
	player->number = number;
	player->size = 0;
	player->code = NULL;
	return (player);
}

void		vm_list_player_add(t_player **list, t_player *add)
{
	if (add)
	{
		add->next = *list;
		*list = add;
	}
}

int			vm_list_player_size(t_player *player)
{
	int size;

	size = 0;
	while (player)
	{
		size++;
		player = player->next;
	}
	return (size);
}
