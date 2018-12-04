/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:50:07 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/21 14:50:09 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vs_draw_frame(int y, int x)
{
	attron(COLOR_PAIR(20));
	while (++y <= (MEM_SIZE >> 6) + 1)
	{
		x = -1;
		while (++x < 292)
			if (!y || !x || x == 196 || y == (MEM_SIZE >> 6) + 1 || x == 291)
				mvwprintw(stdscr, y, x, " ");
			else if (x == 239 || x == 268)
				mvwprintw(stdscr, y, x, " ");
	}
	mvwprintw(stdscr, 0, 100, "MEMORY");
	mvwprintw(stdscr, 0, 212, "STATUS");
	mvwprintw(stdscr, 0, 250, "PROCESS");
	mvwprintw(stdscr, 0, 275, "REGISTRY");
}

static void	vs_fps(int y, int x)
{
	static unsigned int frame;
	static unsigned int fps;
	static time_t		sec;

	frame++;
	mvwprintw(stdscr, y, x, "FPS:     %u", fps);
	if (sec != time(0))
	{
		sec = time(0);
		fps = frame;
		frame = 0;
	}
}

static void	vs_print_players(t_player *p, int y, int x)
{
	attron(COLOR_PAIR(20));
	mvwprintw(stdscr, y++, x - 1, "               PLAYERS                    ");
	while (p)
	{
		attron(COLOR_PAIR(SET_COL(ft_abs(p->number))));
		mvwprintw(stdscr, ++y, x, "%d:", p->number);
		mvwprintw(stdscr, ++y, x, " %.30s", p->name);
		y++;
		p = p->next;
	}
}

static void	vs_print_alive(t_core *core, t_player *p, int y, int x)
{
	attron(COLOR_PAIR(20));
	mvwprintw(stdscr, y++, x - 1, core->cycle_to_die && core->proc ?
		"              LAST ALIVE                   " :
		"               WINER!!!                    ");
	if (core->last_alive)
	{
		attron(COLOR_PAIR(SET_COL(ft_abs(p->number))));
		mvwprintw(stdscr, y + 1, x, "%d:", p->number);
		mvwprintw(stdscr, y + 2, x, " %.30s", p->name);
	}
}

void		vs_status(t_core *core)
{
	vs_draw_frame(-1, -1);
	attron(COLOR_PAIR(10));
	vs_fps(2, 199);
	vs_stats(core, 3, 199);
	vs_print_alive(core, core->last_alive, 8, 198);
	vs_print_players(core->player, 13, 198);
	vs_info(59, 199);
}
