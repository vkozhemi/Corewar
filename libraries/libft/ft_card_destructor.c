/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_card_destructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:58:30 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 17:58:32 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_card_destructor(void **card)
{
	void **rat;

	rat = card;
	while (*card)
	{
		free(*card);
		card++;
	}
	free(rat);
	return (NULL);
}
