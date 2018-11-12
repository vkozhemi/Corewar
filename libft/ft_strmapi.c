/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:30:24 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/27 17:10:01 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*str;

	len = 0;
	if (!s)
		return (0);
	while (*(s + len))
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !s || !*s)
		return (0);
	len = 0;
	while (*s)
	{
		*(str + len) = f(len, *s++);
		len++;
	}
	*(str + len) = '\0';
	return (str);
}
