/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:30:32 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/28 18:30:33 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_llabs(long long int x)
{
	return ((x < 0) ? -x : x);
}

static char	*ft_llnum(char *str, long long int n)
{
	if (n / 10)
		str = ft_llnum(str, n / 10);
	*str++ = (ft_llabs((n % 10)) + '0');
	return (str);
}

char		*pf_putllnbr(long long int n, char *str, t_flag *f)
{
	if (n < 0)
		f->specs = '-';
	ft_llnum(str, n);
	return (str);
}
