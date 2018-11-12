/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:44:26 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/25 13:37:18 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;
	char	*begin;

	len = 0;
	begin = (char *)s1;
	while (*s1++)
		len++;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	while (*begin)
		*s2++ = *begin++;
	*s2 = '\0';
	while (len--)
		s2--;
	return (s2);
}
