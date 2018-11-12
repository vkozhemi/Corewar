/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:08:29 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/29 22:32:30 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *temp1;
	unsigned char *temp2;

	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (n)
	{
		*temp1 = *temp2;
		if (*temp2 == (unsigned char)c)
			return ((void *)++temp1);
		temp2++;
		temp1++;
		n--;
	}
	return (0);
}
