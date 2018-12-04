/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:58:22 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 10:57:15 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	char *rat;

	rat = dest;
	dest += ft_strlen(dest);
	while (*src && len--)
		*dest++ = *src++;
	*dest = '\0';
	return (rat);
}
