/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:08:44 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/27 17:09:51 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*str;

	len = 0;
	if (!s)
		return (0);
	while (*(s + len))
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	len = 0;
	while (*s)
		*(str + len++) = f(*s++);
	*(str + len) = '\0';
	return (str);
}
