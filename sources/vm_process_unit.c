/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_process_unit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:24:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/26 15:24:57 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_get_command(t_core *core, t_proc *proc)
{
	unsigned char com;

	com = MAP(POS);
	if (com && com < ((STATUS & 8) ? 20 : 17))
	{
		COMMAND = com;
		proc->cycle = g_tab[com].cycles - 1;
	}
}

static void	vm_proc_action(t_core *core, t_proc *proc)
{
	if (COMMAND)
		g_tab[COMMAND].func(core, proc);
	else
		vm_proc_move(core->map, proc, 1);
}

static void	vm_proc_manage(t_core *core, t_proc *proc)
{
	while (proc)
	{
		if (!COMMAND)
			vm_get_command(core, proc);
		if (proc->cycle)
			proc->cycle--;
		else
			vm_proc_action(core, proc);
		proc = proc->next;
	}
}

static void	vm_era_manage(t_core *core)
{
	if (core->current_era_cycle >= core->cycle_to_die)
	{
		vm_proc_kill(&core->proc);
		core->era++;
		if (core->alive_shout >= NBR_LIVE || core->era == MAX_CHECKS)
		{
			core->cycle_to_die = (CYCLE_DELTA < core->cycle_to_die) ?
				core->cycle_to_die - CYCLE_DELTA : 0;
			core->era = 0;
		}
		core->alive_shout = 0;
		core->current_era_cycle = 0;
	}
}

void		vm_process_unit(t_core *core)
{
	if (core->cycle_to_die)
	{
		vm_proc_manage(core, core->proc);
		core->current_era_cycle++;
		core->cycle++;
		vm_era_manage(core);
	}
}
