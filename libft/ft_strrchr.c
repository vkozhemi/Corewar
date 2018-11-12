/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:49:55 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/22 14:55:20 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int lastindexc;

	i = 0;
	lastindexc = 0;
	if (c == 0)
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (s[i])
	{
		if (s[i] == c)
			lastindexc = i;
		i++;
	}
	if (lastindexc == 0 && s[0] != c)
		return (0);
	while (lastindexc-- > 0)
		s++;
	return ((char *)s);
}
