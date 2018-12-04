/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_wizard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:41:55 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/23 18:41:57 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	vm_check_macro(void)
{
	if (REG_CODE != 1 || DIR_CODE != 2 || IND_CODE != 3)
		ft_error("broken codage");
	if (MAX_ARGS_NUMBER != 4)
		ft_error("macro error");
	if (MEM_SIZE < 1024 || MEM_SIZE & 63)
		ft_error("invalid size [MEM_SIZE] > 1024 && MEM_SIZE % 64 == 0");
	if (IDX_MOD < 128)
		ft_error("wrong IDX_MOD");
	if (CHAMP_MAX_SIZE != MEM_SIZE / 6)
		ft_error("CHAMP_MAX_SIZE is broken");
	if (REG_NUMBER < 4 || REG_NUMBER > 64)
		ft_error("REG_SIZE must be between 4-128");
	if (CYCLE_TO_DIE < 4 || CYCLE_DELTA < 1 || NBR_LIVE < 3 || MAX_CHECKS < 1)
		ft_error("invalid game rules macro");
	if (PROG_NAME_LENGTH != 128 || COMMENT_LENGTH != 2048 ||
		COREWAR_EXEC_MAGIC != 0xea83f3)
		ft_error("invalid asm macro");
}

static void	vm_initcore(t_core *core)
{
	if (!(core->map = (UC *)ft_memalloc(sizeof(UC) * MEM_SIZE)))
		ft_error("couldn't allocate memory");
	if (!(core->color = (UC *)ft_memalloc(sizeof(UC) * MEM_SIZE)))
		ft_error("couldn't allocate memory");
	ft_memset(core->color, 10, MEM_SIZE);
	core->player = NULL;
	core->last_alive = NULL;
	core->proc = NULL;
	core->cycle_to_die = CYCLE_TO_DIE;
	core->current_era_cycle = 0;
	core->era = 0;
	core->cycle_todecrease = 0;
	core->alive_shout = 0;
	core->cycle = 0;
	core->print = 1;
	core->status = 0;
	core->dump = 0;
}

int			vm_isnumber(char *str)
{
	if (!str)
		ft_error("no argument");
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

static char	**vm_get_flags(t_core *core, char **args)
{
	while (*args)
	{
		if (!ft_strcmp(*args, "-a"))
			STATUS |= 8;
		else if (!ft_strcmp(*args, "-v"))
			STATUS |= 1;
		else if (!ft_strcmp(*args, "-d"))
		{
			args++;
			if (vm_isnumber(*args))
				ft_error("bad argument after -d");
			core->dump = ft_atoi(*args);
		}
		else
			break ;
		args++;
	}
	return (args);
}

void		vm_wizard(char **card)
{
	t_core		core;

	vm_check_macro();
	vm_initcore(&core);
	card = vm_get_flags(&core, card);
	vm_get_players(&core, card);
	if (core.status & 1)
		vm_visual(&core);
	else
		vm_bomj(&core);
}
