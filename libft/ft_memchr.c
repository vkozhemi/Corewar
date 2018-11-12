/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:44:13 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/23 19:45:55 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)s;
	while (n)
	{
		if (*temp == (unsigned char)c)
			return (temp);
		temp++;
		n--;
	}
	return (NULL);
}
