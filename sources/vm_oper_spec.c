/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_oper_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:07:42 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/10 18:07:45 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_fork(t_core *core, t_proc *proc)
{
	int		val;
	t_proc	*new;

	val = (vm_get_val(core, POS + 1, 2) % IDX_MOD);
	new = vm_list_proc_new(REG(1), MAP(val), (POS + val));
	vm_proc_move(core->map, new, 0);
	val = 16;
	while (val--)
		new->reg[val] = proc->reg[val];
	new->alive = proc->alive;
	new->carry = proc->carry;
	vm_list_proc_add(&core->proc, new);
	vm_proc_move(core->map, proc, 3);
}

void	op_zjmp(t_core *core, t_proc *proc)
{
	int val;

	val = vm_get_val(core, POS + 1, 2) % IDX_MOD;
	if (proc->carry)
		vm_proc_move(core->map, proc, val);
	else
		vm_proc_move(core->map, proc, 3);
}

void	op_lfork(t_core *core, t_proc *proc)
{
	int		val;
	t_proc	*new;

	val = vm_get_val(core, POS + 1, 2);
	new = vm_list_proc_new(REG(1), MAP(val), (POS + val));
	vm_proc_move(core->map, new, 0);
	val = 16;
	while (val--)
		new->reg[val] = proc->reg[val];
	new->alive = proc->alive;
	new->carry = proc->carry;
	vm_list_proc_add(&core->proc, new);
	vm_proc_move(core->map, proc, 3);
}

void	op_aff(t_core *core, t_proc *proc)
{
	unsigned char	arg;

	arg = MAP(POS + 1);
	if (ARG1(arg) == 0b01 && C_INDX(MAP(POS + 2)))
	{
		ft_printf("%c", REG(MAP(POS + 2)));
	}
	vm_proc_move(core->map, proc, vm_move(arg, 4, 1));
}
