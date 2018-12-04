/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:30:20 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/28 18:30:21 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_labs(long int x)
{
	return ((x < 0) ? -x : x);
}

static char	*ft_lnum(char *str, long int n)
{
	if (n / 10)
		str = ft_lnum(str, n / 10);
	*str++ = (ft_labs((n % 10)) + '0');
	return (str);
}

char		*pf_putlnbr(long int n, char *str, t_flag *f)
{
	if (n < 0)
		f->specs = '-';
	ft_lnum(str, n);
	return (str);
}
