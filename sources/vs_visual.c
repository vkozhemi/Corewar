/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:58:48 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/24 15:58:50 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vs_map(unsigned char *map, unsigned char *color, int size)
{
	int y;
	int x;

	y = 1;
	while (size)
	{
		x = 0;
		while (++x < 65)
		{
			attron(COLOR_PAIR(*color));
			mvwprintw(stdscr, y, (x * 3), "%02x", *map);
			map++;
			color++;
			size--;
		}
		y++;
	}
}

void		vs_render(t_core *core)
{
	vs_map(core->map, core->color, MEM_SIZE);
	vs_proc(core, core->proc, 1, 240);
	vs_status(core);
	wrefresh(stdscr);
}
