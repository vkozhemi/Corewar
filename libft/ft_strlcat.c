/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:24:13 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/27 16:56:16 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;
	size_t i;
	size_t res;

	i = 0;
	res = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + slen);
	res = dlen + slen;
	while (src[i] != '\0')
	{
		if (dlen < dstsize - 1)
		{
			dst[dlen] = src[i];
			dlen++;
		}
		i++;
	}
	dst[dlen] = '\0';
	return (res);
}
