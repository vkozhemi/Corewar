/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:48:12 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 18:58:43 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	while (len)
	{
		*(unsigned char*)dest++ = *(unsigned char*)src++;
		if (*(unsigned char*)(dest - 1) == (unsigned char)c)
			return (dest);
		len--;
	}
	return (NULL);
}
