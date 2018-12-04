/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:38:22 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/28 18:38:28 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putllx(char *str, ULLI n, int base, char *dip)
{
	if (n >> base)
		str = putllx(str, n >> base, base, dip);
	*str++ = (dip[n & (1 << base) - 1]);
	return (str);
}

char		*pf_putllx(ULLI n, int base, char *str, int sharp)
{
	if (sharp && n)
	{
		str[0] = '0';
		if (base < 4)
			putllx(&str[1], n, base, "0123456789abcdef");
		else
		{
			str[1] = 'x';
			putllx(&str[2], n, base, "0123456789abcdef");
		}
	}
	else
		putllx(str, n, base, "0123456789abcdef");
	return (str);
}

char		*pf_putupllx(ULLI n, int base, char *str, int sharp)
{
	if (sharp && n)
	{
		str[0] = '0';
		str[1] = 'X';
		putllx(&str[2], n, base, "0123456789ABCDEF");
	}
	else
		putllx(str, n, base, "0123456789ABCDEF");
	return (str);
}
