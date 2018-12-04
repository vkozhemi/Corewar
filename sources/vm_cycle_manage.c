/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle_manage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:28:18 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/20 16:28:20 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_visual(t_core *core)
{
	vs_init();
	system("afplay music/exist.mp3 &");
	while (1)
	{
		werase(stdscr);
		if ((STATUS & 0x6) && core->proc)
		{
			STATUS &= 0xfb;
			vm_process_unit(core);
		}
		vs_render(core);
		vs_input(core);
	}
}

void	vm_bomj(t_core *core)
{
	while (core->cycle_to_die && core->proc)
	{
		if (core->proc)
			vm_process_unit(core);
		if (core->dump == core->cycle)
			vm_dump(core->map);
	}
	ft_printf("Player %d: '%s', has won!\n",
		core->last_alive->number, core->last_alive->name);
	exit(0);
}
