/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_oper_def.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:31:33 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/01 13:31:34 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	op_player_alive(t_core *core, t_player *player, int live)
{
	while (player)
	{
		if (live == player->number)
		{
			core->last_alive = player;
			if (!(core->status & 1))
				ft_printf("A process shows that player %d '%s' is alive\n",
					player->number, player->name);
			return ;
		}
		player = player->next;
	}
}

void		op_live(t_core *core, t_proc *proc)
{
	int live;

	proc->alive |= 1;
	live = vm_get_val(core, POS + 1, 4);
	core->alive_shout++;
	op_player_alive(core, core->player, live);
	vm_proc_move(core->map, proc, 5);
}

void		op_ld(t_core *core, t_proc *proc)
{
	unsigned char	arg;
	int				val;

	arg = MAP(POS + 1);
	if (ARG2(arg) == 0b01)
	{
		if (ARG1(arg) == 0b10 && C_INDX(MAP(POS + 6)))
		{
			val = vm_get_val(core, POS + 2, 4);
			REG(MAP(POS + 6)) = val;
			proc->carry = val ? 0 : 1;
		}
		else if (ARG1(arg) == 0b11 && C_INDX(MAP(POS + 4)))
		{
			val = vm_get_val(core, POS + 2, 2) % IDX_MOD;
			val = vm_get_val(core, POS + val, 4);
			REG(MAP(POS + 4)) = val;
			proc->carry = val ? 0 : 1;
		}
	}
	vm_proc_move(core->map, proc, vm_move(arg, 4, 2));
}

void		op_st(t_core *core, t_proc *proc)
{
	UC	arg;
	int	val;

	arg = MAP(POS + 1);
	if (ARG1(arg) == 0b01 && C_INDX(MAP(POS + 2)))
	{
		if (ARG2(arg) == 0b11)
		{
			val = vm_get_val(core, POS + 3, 2);
			vm_set_map(core, proc, (unsigned int)REG(MAP(POS + 2)),
				(POS + (val % IDX_MOD) + 3));
		}
		else if (ARG2(arg) == 0b01 && C_INDX(MAP(POS + 3)))
			REG(MAP(POS + 3)) = REG(MAP(POS + 2));
	}
	vm_proc_move(core->map, proc, vm_move(arg, 4, 2));
}
