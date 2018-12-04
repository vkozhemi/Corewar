/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:54:36 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 19:00:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*rat;
	int		index;

	str = NULL;
	index = 0;
	if (s && f)
		str = ft_strnew(ft_strlen(s));
	rat = str;
	if (str)
	{
		while (*s)
			*str++ = f(index++, *s++);
		*str = '\0';
	}
	return (rat);
}
