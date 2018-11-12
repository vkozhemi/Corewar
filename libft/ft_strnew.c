/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:58:14 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/24 12:00:31 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char	*temp;
	unsigned char	*begin;

	temp = (unsigned char *)malloc(sizeof(unsigned char) * (size + 1));
	if (!temp)
		return (0);
	begin = temp;
	while (size--)
		*temp++ = '\0';
	*temp = '\0';
	return ((char *)begin);
}
