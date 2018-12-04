/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:55:26 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/21 10:55:28 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bin_len(UI val)
{
	int len;

	len = 0;
	while (val)
	{
		val >>= 1;
		len++;
	}
	return (len);
}

static void	ft_unimask(UI v, unsigned char *o)
{
	*o++ = ((UI)4034953344 >> 24) | ((v >> 18) << 29) >> 29;
	*o++ = (((UI)4034953344 << 8) >> 24) | ((v >> 12) << 26) >> 26;
	*o++ = (((UI)4034953344 << 16) >> 24) | ((v >> 6) << 26) >> 26;
	*o = (((UI)4034953344 << 24) >> 24) | (v << 26) >> 26;
}

int			pf_uniparser(UI v, unsigned char *o)
{
	int	len;

	len = ft_bin_len(v);
	if (len <= 7)
	{
		*o = v;
		return (1);
	}
	else if (len <= 11)
	{
		*o++ = ((UI)49280 >> 8) | ((v >> 6) << 27) >> 27;
		*o = (((UI)49280 << 24) >> 24) | (v << 26) >> 26;
		return (2);
	}
	else if (len <= 16)
	{
		*o++ = ((UI)14712960 >> 16) | ((v >> 12) << 28) >> 28;
		*o++ = (((UI)14712960 << 16) >> 24) | ((v >> 6) << 26) >> 26;
		*o = (((UI)14712960 << 24) >> 24) | (v << 26) >> 26;
		return (3);
	}
	ft_unimask(v, o);
	return (4);
}