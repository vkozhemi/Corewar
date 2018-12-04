/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:58:22 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/23 13:58:23 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putx(char *str, unsigned int n, int base, char *dip)
{
	if (n >> base)
		str = putx(str, n >> base, base, dip);
	*str++ = (dip[n & (1 << base) - 1]);
	return (str);
}

char		*pf_putx(unsigned int n, int base, char *str, int sharp)
{
	if (sharp && n)
	{
		str[0] = '0';
		if (base < 4)
			putx(&str[1], n, base, "0123456789abcdef");
		else
		{
			str[1] = 'x';
			putx(&str[2], n, base, "0123456789abcdef");
		}
	}
	else
		putx(str, n, base, "0123456789abcdef");
	return (str);
}

char		*pf_putupx(unsigned int n, int base, char *str, int sharp)
{
	if (sharp && n)
	{
		str[0] = '0';
		str[1] = 'X';
		putx(&str[2], n, base, "0123456789ABCDEF");
	}
	else
		putx(str, n, base, "0123456789ABCDEF");
	return (str);
}
