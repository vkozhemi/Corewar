/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:11:53 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/19 20:11:55 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_fillmap(t_core *core, int start, UC *code, t_player *player)
{
	UC	*map;
	UC	*color;
	int	size;

	size = player->size;
	map = core->map;
	color = core->color;
	while (start--)
	{
		map++;
		color++;
	}
	while (size--)
	{
		*map++ = *code++;
		*color++ = SET_COL(ft_abs(player->number));
	}
}

void	vm_place_players(t_core *core, t_player *player, t_proc *proc)
{
	int size;
	int interval;
	int start;

	size = vm_list_player_size(player);
	if (size > MAX_PLAYERS)
		ft_error("too many players");
	interval = MEM_SIZE / size;
	while (player && proc)
	{
		start = interval * (--size);
		vm_fillmap(core, start, player->code, player);
		vm_proc_move(core->map, proc, start);
		player = player->next;
		proc = proc->next;
	}
}

void	vm_get_players(t_core *core, char **card)
{
	int i;
	int num;

	i = -1;
	if (!*card)
		ft_error("no players found");
	while (*card)
	{
		if (!ft_strcmp(*card, "-n"))
		{
			card++;
			if (vm_isnumber(*card))
				ft_error("bad argument after -n");
			num = ft_atoi(*card++);
		}
		else
			num = i;
		vm_list_player_add(&core->player, vm_readfile(*card, num));
		vm_list_proc_add(&core->proc, vm_list_proc_new(num, 0, 0));
		card++;
		i--;
	}
	vm_place_players(core, core->player, core->proc);
}
