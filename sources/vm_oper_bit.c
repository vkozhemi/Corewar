/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_oper_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:20:08 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/10 16:20:09 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	vm_arg(t_core *core, t_proc *proc, UC arg, unsigned int pos)
{
	if (arg == 0b01)
		return (REG(MAP(pos)));
	else if (arg == 0b10)
		return (vm_get_val(core, pos, 4));
	else
		return (vm_get_val(core, POS + vm_get_val(core, pos, 2), 4));
}

void		op_and(t_core *core, t_proc *proc)
{
	UC	arg;
	int	amount;
	int	tmp_pos;
	int	val[3];

	amount = 3;
	tmp_pos = POS + 2;
	arg = MAP(POS + 1);
	if (ARG1(arg) && ARG2(arg) && ARG3(arg) == 0b01)
		while (amount)
		{
			arg = (MAP(POS + 1) >> (amount-- << 1)) & 0b11;
			if (arg == 0b01 && !C_INDX(MAP(tmp_pos)))
				break ;
			if (amount)
				val[amount] = vm_arg(core, proc, arg, tmp_pos);
			else
			{
				REG(MAP(tmp_pos)) = val[2] & val[1];
				proc->carry = REG(MAP(tmp_pos)) ? 0 : 1;
			}
			tmp_pos += vm_get_gap(arg, 4);
		}
	vm_proc_move(core->map, proc, vm_move(MAP(POS + 1), 4, 3));
}

void		op_or(t_core *core, t_proc *proc)
{
	UC	arg;
	int	amount;
	int	tmp_pos;
	int	val[3];

	amount = 3;
	tmp_pos = POS + 2;
	arg = MAP(POS + 1);
	if (ARG1(arg) && ARG2(arg) && ARG3(arg) == 0b01)
		while (amount)
		{
			arg = (MAP(POS + 1) >> (amount-- << 1)) & 0b11;
			if (arg == 0b01 && !C_INDX(MAP(tmp_pos)))
				break ;
			if (amount)
				val[amount] = vm_arg(core, proc, arg, tmp_pos);
			else
			{
				REG(MAP(tmp_pos)) = val[2] | val[1];
				proc->carry = REG(MAP(tmp_pos)) ? 0 : 1;
			}
			tmp_pos += vm_get_gap(arg, 4);
		}
	vm_proc_move(core->map, proc, vm_move(MAP(POS + 1), 4, 3));
}

void		op_xor(t_core *core, t_proc *proc)
{
	UC	arg;
	int	amount;
	int	tmp_pos;
	int	val[3];

	amount = 3;
	tmp_pos = POS + 2;
	arg = MAP(POS + 1);
	if (ARG1(arg) && ARG2(arg) && ARG3(arg) == 0b01)
		while (amount)
		{
			arg = (MAP(POS + 1) >> (amount-- << 1)) & 0b11;
			if (arg == 0b01 && !C_INDX(MAP(tmp_pos)))
				break ;
			if (amount)
				val[amount] = vm_arg(core, proc, arg, tmp_pos);
			else
			{
				REG(MAP(tmp_pos)) = val[2] ^ val[1];
				proc->carry = REG(MAP(tmp_pos)) ? 0 : 1;
			}
			tmp_pos += vm_get_gap(arg, 4);
		}
	vm_proc_move(core->map, proc, vm_move(MAP(POS + 1), 4, 3));
}
