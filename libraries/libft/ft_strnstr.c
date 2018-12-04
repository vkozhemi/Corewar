/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:20:40 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 14:46:35 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	size;

	while (!*str1)
		str1++;
	if (*str2)
	{
		size = ft_strlen(str2);
		while (len && len-- >= size && *str1)
		{
			if (!ft_strncmp(str1, str2, size))
				return ((char *)str1);
			str1++;
		}
		return (NULL);
	}
	return ((char *)str1);
}
