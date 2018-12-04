/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:24:12 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/28 18:33:51 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *str, char c)
{
	size_t size;

	size = 0;
	str = ft_skip_char(str, c);
	while (*str)
	{
		while (*str && *str != c)
			str++;
		str = ft_skip_char(str, c);
		size++;
	}
	return (size);
}
