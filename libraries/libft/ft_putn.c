/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:43:01 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/27 16:05:55 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_num(char *str, int n)
{
	str[1] = '\0';
	if (n / 10)
		str = ft_num(str, n / 10);
	*str++ = (ft_abs(n % 10) + '0');
	return (str);
}

char		*pf_putnbr(int n, char *str, t_flag *f)
{
	if (n < 0)
		f->specs = '-';
	ft_num(str, n);
	return (str);
}
