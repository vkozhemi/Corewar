/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_nstuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:38:27 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/21 14:38:29 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vs_init_color(void)
{
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, 12, COLOR_BLACK);
	init_pair(6, 214, COLOR_BLACK);
	init_pair(7, 14, COLOR_BLACK);
	init_pair(8, 200, COLOR_BLACK);
	init_pair(9, 8, COLOR_BLACK);
	init_pair(10, 15, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	init_pair(13, COLOR_BLACK, COLOR_RED);
	init_pair(14, COLOR_BLACK, COLOR_YELLOW);
	init_pair(15, COLOR_BLACK, 12);
	init_pair(16, COLOR_BLACK, 214);
	init_pair(17, COLOR_BLACK, 14);
	init_pair(18, COLOR_BLACK, 200);
	init_pair(19, COLOR_BLACK, 8);
	init_pair(20, COLOR_BLACK, 15);
}

void		vs_init(void)
{
	initscr();
	curs_set(0);
	noecho();
	vs_init_color();
	nodelay(stdscr, true);
}

void		vs_input(t_core *core)
{
	UC ch;

	ch = getch();
	if (ch == ' ')
		core->status ^= 0x2;
	if (ch == 'e')
		core->status |= 0x4;
	if (ch == 's')
		core->print++;
	if (ch == 'w')
		core->print--;
	if (ch == 'q')
	{
		endwin();
		system("killall afplay");
		exit(0);
	}
}
