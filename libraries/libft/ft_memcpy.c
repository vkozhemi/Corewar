/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:13:32 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 18:10:00 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	void *rat;

	if (!dest && !src)
		return (NULL);
	rat = dest;
	while (len)
	{
		*(unsigned char*)rat++ = *(unsigned char*)src++;
		len--;
	}
	return (dest);
}
