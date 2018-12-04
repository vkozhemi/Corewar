/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:21:05 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/22 12:31:05 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int symbol)
{
	while (*str)
	{
		if (*str == symbol)
			return (str);
		str++;
	}
	if (*str == symbol)
		return (str);
	return (NULL);
}
