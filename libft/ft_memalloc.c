/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:04:08 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/23 21:01:05 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*arr;
	size_t	*begin;
	void	*res;

	arr = (size_t *)malloc(sizeof(size_t) * size);
	if (!arr)
		return (0);
	begin = arr;
	while (size--)
		*arr++ = 0;
	res = (void *)begin;
	return (res);
}
