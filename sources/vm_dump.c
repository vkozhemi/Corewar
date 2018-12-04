/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:14:07 by vkaidans          #+#    #+#             */
/*   Updated: 2018/11/20 16:14:09 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	vm_dump(unsigned char *memory)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (!(i & 63))
			ft_printf("%#06x : ", i);
		if ((i + 1) & 63)
			ft_printf("%02x ", *memory);
		else
			ft_printf("%02x\n", *memory);
		memory++;
	}
	exit(0);
}
