/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:50:31 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 14:36:57 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t dest_len;

	dest_len = ft_strlen(dest);
	if (len <= dest_len)
		return (len + ft_strlen((char *)src));
	ft_strncat(dest, src, len - dest_len - 1);
	return (dest_len + ft_strlen((char *)src));
}
