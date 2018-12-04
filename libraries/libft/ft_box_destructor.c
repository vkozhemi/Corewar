/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_destructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:58:58 by vkaidans          #+#    #+#             */
/*   Updated: 2018/04/17 17:59:07 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	***ft_box_destructor(void ***box)
{
	void ***rat;

	rat = box;
	while (*box)
	{
		*box = ft_card_destructor(*box);
		box++;
	}
	free(rat);
	return (NULL);
}
