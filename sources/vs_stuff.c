/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_stuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:19:59 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/21 19:20:01 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vs_stats(t_core *core, int y, int x)
{
	mvwprintw(stdscr, y++, x, "Cycle:   %u", core->cycle);
	mvwprintw(stdscr, y++, x, "Current: %d / %d",
		core->current_era_cycle, core->cycle_to_die);
	mvwprintw(stdscr, y++, x, "Period:  %d / %d", core->era, MAX_CHECKS);
	mvwprintw(stdscr, y, x, "Alive:   %d / %d", core->alive_shout, NBR_LIVE);
}

void	vs_info(int y, int x)
{
	attron(COLOR_PAIR(20));
	mvwprintw(stdscr, y++, x - 2, "                INFO                      ");
	attron(COLOR_PAIR(10));
	mvwprintw(stdscr, ++y, x, " SPACE   pause");
	mvwprintw(stdscr, ++y, x, " 'E'     step move");
	mvwprintw(stdscr, ++y, x, " 'W'/'S' process move");
}
