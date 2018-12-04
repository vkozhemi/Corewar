/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:04:43 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/28 16:34:13 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *meme, int val, size_t len)
{
	while (len--)
		if (*(unsigned char*)meme++ == (unsigned char)val)
			return ((void *)meme - 1);
	return (NULL);
}
