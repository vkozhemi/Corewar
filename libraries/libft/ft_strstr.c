/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:26:14 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/26 18:52:27 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	len;

	if (*str2)
	{
		len = ft_strlen(str2);
		while (*str1)
		{
			if (!ft_strncmp(str1, str2, len))
				return ((char *)str1);
			str1++;
		}
		return (NULL);
	}
	return ((char *)str1);
}
