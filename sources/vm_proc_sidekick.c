/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_proc_sidekick.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:29:53 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/31 15:29:54 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_proc_move(unsigned char *map, t_proc *proc, int move)
{
	(void)map;
	POS = (unsigned int)(POS + move) % MEM_SIZE;
	COMMAND = 0;
	proc->cycle = 0;
}

int		vm_get_gap(unsigned char arg, int label)
{
	if (arg == 0b01)
		return (1);
	if (arg == 0b10)
		return (label);
	if (arg == 0b11)
		return (2);
	return (0);
}

int		vm_move(unsigned char arg, unsigned char label, unsigned char amount)
{
	int ret;

	ret = 2;
	while (++amount <= 4)
		arg >>= 2;
	while (arg)
	{
		ret += vm_get_gap(arg & 0b11, label);
		arg >>= 2;
	}
	return (ret);
}

int		vm_get_val(t_core *core, unsigned int pos, int bytes)
{
	UC buff[bytes];

	if (bytes == 2)
	{
		buff[0] = core->map[(pos + 1) % MEM_SIZE];
		buff[1] = core->map[pos % MEM_SIZE];
		return (*(short *)&buff[0]);
	}
	if (bytes == 4)
	{
		buff[0] = core->map[(pos + 3) % MEM_SIZE];
		buff[1] = core->map[(pos + 2) % MEM_SIZE];
		buff[2] = core->map[(pos + 1) % MEM_SIZE];
		buff[3] = core->map[pos % MEM_SIZE];
		return (*(int *)&buff[0]);
	}
	return (-1);
}

void	vm_set_map(t_core *core, t_proc *proc,
	unsigned int val, unsigned int addr)
{
	int i;

	i = 4;
	while (i--)
	{
		COLOR(addr) = SET_COL(ft_abs(REG(1)));
		MAP(addr--) = val & 0xFF;
		val >>= 8;
	}
}
