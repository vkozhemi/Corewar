/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_oper_ilong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:07:25 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/10 18:07:27 by vkaidans         ###   ########.fr       */
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

void		op_ldi(t_core *core, t_proc *proc)
{
	UC	arg;
	UC	arg_buff;
	int	amount;
	int	t;
	int	v[3];

	amount = 3;
	t = POS + 2;
	arg = MAP(POS + 1);
	if (ARG1(arg) && (ARG2(arg) == 0b01 || ARG2(arg) == 0b10)
		&& ARG3(arg) == 0b01)
		while (amount)
		{
			arg_buff = (MAP(POS + 1) >> (amount-- << 1)) & 0b11;
			if (arg_buff == 0b01 && !C_INDX(MAP(t)))
				break ;
			if (amount)
				v[amount] = vm_arg(core, proc, arg_buff, t);
			else
				REG(MAP(t)) =
					vm_get_val(core, ((v[2] + v[1]) % IDX_MOD) + POS, 4);
			t += vm_get_gap(arg_buff, 2);
		}
	vm_proc_move(core->map, proc, vm_move(arg, 2, 3));
}

void		op_sti(t_core *core, t_proc *proc)
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
					POS + ((val[0] + val[1]) % IDX_MOD) + 3);
			tmp_pos += vm_get_gap(arg_buff, 2);
		}
	vm_proc_move(core->map, proc, vm_move(arg, 2, 3));
}

void		op_lld(t_core *core, t_proc *proc)
{
	UC	arg;
	int	val;

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
			val = vm_get_val(core, POS + 2, 2);
			val = vm_get_val(core, POS + val, 4);
			REG(MAP(POS + 4)) = val;
			proc->carry = val ? 0 : 1;
		}
	}
	vm_proc_move(core->map, proc, vm_move(arg, 4, 2));
}

void		op_lldi(t_core *core, t_proc *proc)
{
	UC	arg;
	UC	arg_buff;
	int	val[5];

	val[3] = 3;
	val[4] = POS + 2;
	arg = MAP(POS + 1);
	if (ARG1(arg) && (ARG2(arg) == 0b01 || ARG2(arg) == 0b10)
		&& ARG3(arg) == 0b01)
		while (val[3])
		{
			arg_buff = (arg >> (val[3]-- << 1)) & 0b11;
			if (arg_buff == 0b01 && !C_INDX(MAP(val[4])))
				break ;
			if (val[3])
				val[val[3]] = vm_arg(core, proc, arg_buff, val[4]);
			else
			{
				val[0] = vm_get_val(core, (val[2] + val[1]) + POS, 4);
				REG(MAP(val[4])) = val[0];
				proc->carry = val[0] ? 0 : 1;
			}
			val[4] += vm_get_gap(arg_buff, 2);
		}
	vm_proc_move(core->map, proc, vm_move(arg, 2, 3));
}
