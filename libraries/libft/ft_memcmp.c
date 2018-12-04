/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:01:11 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 18:17:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *meme1, const void *meme2, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)meme1 != *(unsigned char *)meme2)
			return (*(unsigned char *)meme1 - *(unsigned char *)meme2);
		meme1++;
		meme2++;
	}
	return (0);
}
