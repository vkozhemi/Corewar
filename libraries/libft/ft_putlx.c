/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:38:01 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/28 18:38:02 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putlx(char *str, unsigned long int n, int base, char *dip)
{
	if (n >> base)
		str = putlx(str, n >> base, base, dip);
	*str++ = (dip[n & (1 << base) - 1]);
	return (str);
}

char		*pf_putlx(unsigned long int n, int base, char *str, int sharp)
{
	if (sharp && n)
	{
		str[0] = '0';
		if (base < 4)
			putlx(&str[1], n, base, "0123456789abcdef");
		else
		{
			str[1] = 'x';
			putlx(&str[2], n, base, "0123456789abcdef");
		}
	}
	else
		putlx(str, n, base, "0123456789abcdef");
	return (str);
}

char		*pf_putuplx(unsigned long int n, int base, char *str, int sharp)
{
	if (sharp && n)
	{
		str[0] = '0';
		str[1] = 'X';
		putlx(&str[2], n, base, "0123456789ABCDEF");
	}
	else
		putlx(str, n, base, "0123456789ABCDEF");
	return (str);
}

char		*pf_putaddr(unsigned long int p, char *str)
{
	str[0] = '0';
	str[1] = 'x';
	putlx(&str[2], p, 4, "0123456789abcdef");
	return (str);
}
