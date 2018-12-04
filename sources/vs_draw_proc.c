/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_draw_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:56:58 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/23 11:57:45 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_proc	*vs_print_reg(t_proc *proc, int x)
{
	int i;

	i = 0;
	while (i++ < REG_NUMBER)
		mvwprintw(stdscr, i, x + 29, " reg[%2d]: %11d ", i, REG(i));
	return (proc);
}

static void		vs_print_proc(t_core *core, t_proc *proc, int colour)
{
	attron(COLOR_PAIR(colour));
	mvwprintw(stdscr, (POS >> 6) + 1, ((POS & 63) + 1) * 3, "%02x", MAP(POS));
}

static void		vs_bound_pos(t_core *core, int num)
{
	if (core->print >= num)
		core->print = 1;
	else if (core->print < 1)
		core->print = num - 1;
}

void			vs_proc(t_core *core, t_proc *proc, int y, int x)
{
	int		num;
	t_proc	*active;

	active = NULL;
	num = 1;
	while (proc)
	{
		vs_print_proc(core, proc, PRO_COL(ft_abs(REG(1))));
		if (num == core->print)
			active = vs_print_reg(proc, x);
		else
			attron(COLOR_PAIR(SET_COL(ft_abs(REG(1)))));
		if (core->print + 64 > num && core->print - 2 < num)
			mvwprintw(stdscr, y++, x, "%6d [%c][%c] %5s in:%4d ", num,
				proc->alive ? 'A' : ' ', proc->carry ? 'C' : ' ',
				COMMAND ? g_tab[COMMAND].name : "skip",
				proc->cycle);
		proc = proc->next;
		num++;
	}
	if (active)
		vs_print_proc(core, active, 20);
	vs_bound_pos(core, num);
}
