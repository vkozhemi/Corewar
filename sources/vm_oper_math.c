/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_oper_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:43:01 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/31 17:43:03 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_add(t_core *core, t_proc *proc)
{
	unsigned char	arg;
	int				val;

	arg = MAP(POS + 1);
	if (ARG1(arg) == 0b01 && ARG2(arg) == 0b01 && ARG3(arg) == 0b1)
	{
		if (C_INDX(MAP(POS + 2)) && C_INDX(MAP(POS + 3))
			&& C_INDX(MAP(POS + 4)))
		{
			val = REG(MAP(POS + 2)) + REG(MAP(POS + 3));
			proc->carry = val ? 0 : 1;
			REG(MAP(POS + 4)) = val;
		}
	}
	vm_proc_move(core->map, proc, vm_move(arg, 4, 3));
}

void	op_sub(t_core *core, t_proc *proc)
{
	unsigned char	arg;
	int				val;

	arg = MAP(POS + 1);
	if (ARG1(arg) == 0b01 && ARG2(arg) == 0b01 && ARG3(arg) == 0b1)
	{
		if (C_INDX(MAP(POS + 2)) && C_INDX(MAP(POS + 3))
			&& C_INDX(MAP(POS + 4)))
		{
			val = REG(MAP(POS + 2)) - REG(MAP(POS + 3));
			proc->carry = val ? 0 : 1;
			REG(MAP(POS + 4)) = val;
		}
	}
	vm_proc_move(core->map, proc, vm_move(arg, 4, 3));
}
