/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:38:01 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/29 14:11:33 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *rat;

	rat = dst;
	while (*src && len)
	{
		*dst++ = *src++;
		len--;
	}
	while (len)
	{
		*dst++ = '\0';
		len--;
	}
	return (rat);
}
