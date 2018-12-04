/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_oper_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:56:03 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/22 16:56:05 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	vm_arg(t_core *core, t_proc *proc, UC arg, unsigned int pos)
{
	if (arg == 0b01)
		return (REG(MAP(pos)));
	else if (arg == 0b10)
		return (vm_get_val(core, pos, 2));
	else
		return (vm_get_val(core,
			POS + (vm_get_val(core, pos, 2) % IDX_MOD), 4));
}

void		op_ljmp(t_core *core, t_proc *proc)
{
	if (proc->carry)
		vm_proc_move(core->map, proc, vm_get_val(core, POS + 1, 2));
	else
		vm_proc_move(core->map, proc, 3);
}

void		op_lst(t_core *core, t_proc *proc)
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
				(POS + val + 3));
		}
		else if (ARG2(arg) == 0b01 && C_INDX(MAP(POS + 3)))
			REG(MAP(POS + 3)) = REG(MAP(POS + 2));
	}
	vm_proc_move(core->map, proc, vm_move(arg, 4, 2));
}

void		op_lsti(t_core *core, t_proc *proc)
{
	UC	arg;
	UC	arg_buff;
	int	amount;
	int	tmp_pos;
	int	val[3];

	amount = 3;
	tmp_pos = POS + 2;
	arg = MAP(POS + 1);
	if (ARG1(arg) == 0b01 && ARG2(arg) &&
		(ARG3(arg) == 0b01 || ARG3(arg) == 0b10))
		while (amount)
		{
			arg_buff = (arg >> (amount-- << 1)) & 0b11;
			if (arg_buff == 0b01 && !C_INDX(MAP(tmp_pos)))
				break ;
			val[amount] = vm_arg(core, proc, arg_buff, tmp_pos);
			if (!amount)
				vm_set_map(core, proc, val[2],
					POS + (val[0] + val[1]) + 3);
			tmp_pos += vm_get_gap(arg_buff, 2);
		}
	vm_proc_move(core->map, proc, vm_move(arg, 2, 3));
}
