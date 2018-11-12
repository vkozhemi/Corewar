/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:45:47 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 13:10:47 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char *str)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			word++;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'
					&& str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}
