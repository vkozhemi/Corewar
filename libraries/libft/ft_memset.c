/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:32:27 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/29 14:21:12 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int val, size_t len)
{
	void *rat;

	rat = mem;
	while (len)
	{
		*(char *)mem++ = (unsigned char)val;
		len--;
	}
	return (rat);
}
