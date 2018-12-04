/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:28:54 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 18:59:54 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *rat;

	str = NULL;
	if (s && f)
		str = ft_strnew(ft_strlen(s));
	rat = str;
	if (str)
	{
		if (str)
		{
			while (*s)
				*str++ = f(*s++);
			*str = '\0';
		}
	}
	return (rat);
}
