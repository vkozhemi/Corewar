/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:34:03 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 18:16:56 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memcpy_rev(void *dest, const void *src, size_t len)
{
	dest += len - 1;
	src += len - 1;
	while (len)
	{
		*(unsigned char *)dest-- = *(unsigned char *)src--;
		len--;
	}
}

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		(ft_memcpy(dest, src, len));
	else
		(ft_memcpy_rev(dest, src, len));
	return (dest);
}
