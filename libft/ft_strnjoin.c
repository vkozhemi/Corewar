/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:09:26 by msakovyc          #+#    #+#             */
/*   Updated: 2018/04/24 15:09:29 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*newstr;
	size_t	s1len;
	size_t	s2len;

	if (!s2)
		return (0);
	s1len = ft_strlen(s1);
	newstr = (char *)malloc(sizeof(char) * (s1len + n + 1));
	s1len = 0;
	s2len = 0;
	if (!newstr)
		return (0);
	while (s1 && s1[s1len])
	{
		newstr[s1len] = (char)s1[s1len];
		s1len++;
	}
	while (s2[s2len] && n-- > 0)
		newstr[s1len++] = (char)s2[s2len++];
	newstr[s1len] = '\0';
	return (newstr);
}
