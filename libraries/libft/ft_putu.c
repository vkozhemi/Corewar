/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:37:12 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/23 15:37:15 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*putu(char *str, unsigned long long int n)
{
	if (n / 10)
		str = putu(str, n / 10);
	*str++ = (n % 10 + '0');
	return (str);
}

char		*pf_putu(unsigned long long int n, char *str)
{
	putu(str, n);
	return (str);
}
