/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_list_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:56:48 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/25 16:56:50 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc	*vm_list_proc_new(unsigned int number, UC command, unsigned int pos)
{
	t_proc	*proc;

	if (!(proc = malloc(sizeof(t_proc))))
		ft_error("couldn't allocate memory");
	proc->command = command;
	proc->pos = pos % MEM_SIZE;
	proc->alive = 1;
	proc->carry = 0;
	proc->cycle = 0;
	ft_bzero((void *)proc->reg, 16);
	REG(1) = number;
	proc->next = NULL;
	return (proc);
}

void	vm_list_proc_add(t_proc **list, t_proc *new)
{
	if (new)
	{
		new->next = *list;
		*list = new;
	}
}

void	vm_list_proc_adde(t_proc **list, t_proc *new)
{
	t_proc *tmp;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*list = new;
}

void	vm_list_proc_del(t_proc **proc)
{
	t_proc *tmp;

	tmp = *proc;
	*proc = tmp->next;
	free(tmp);
}

void	vm_proc_kill(t_proc **proc)
{
	t_proc *tmp;
	t_proc *next;

	while (*proc && !(*proc)->alive)
		vm_list_proc_del(proc);
	tmp = *proc;
	if (tmp)
	{
		tmp->alive = 0;
		if (tmp->next)
		{
			next = tmp->next;
			vm_proc_kill(&next);
			tmp->next = next;
		}
	}
}
