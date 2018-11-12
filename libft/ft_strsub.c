/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:42:52 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/27 17:23:08 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	i = 0;
	if (!s || !*s)
		return (0);
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	while (len)
	{
		*(subs + i++) = *(s + start++);
		len--;
	}
	*(subs + i) = '\0';
	return (subs);
}
