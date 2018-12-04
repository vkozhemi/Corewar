/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:16:26 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/22 13:20:21 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int symbol)
{
	char *rat;

	rat = NULL;
	while (*str)
	{
		if (*str == symbol)
			rat = str;
		str++;
	}
	if (*str == symbol)
		rat = str;
	return (rat);
}
