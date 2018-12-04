/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:48:45 by vkaidans          #+#    #+#             */
/*   Updated: 2018/10/23 12:48:46 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_usage(void)
{
	ft_printf("usage: corewar [flag] [player]\n");
	ft_printf("	flags: -d dump, -v visual, -a advanced mode\n");
	ft_printf("	player: [-n number] file_name\n");
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		vm_wizard(++argv);
	else
		vm_usage();
	return (0);
}
