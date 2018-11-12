/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:34:46 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/27 17:31:31 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, char *needle, size_t len)
{
	size_t		i;

	i = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (i > len)
		{
			return (0);
		}
		else
		{
			if (!ft_strncmp(haystack, needle, i))
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (0);
}
