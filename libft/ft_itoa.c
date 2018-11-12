/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:44:53 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/29 22:45:18 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		ft_memitoa(int nbr)
{
	int		iter;

	iter = 0;
	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr *= -1;
		iter++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		iter++;
	}
	return (iter);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		iter;
	int		minus;

	iter = 1;
	iter = ft_memitoa(n);
	if ((minus = 0) == 0 && n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(res = (char*)malloc(sizeof(char) * (iter + 1))))
		return (0);
	res[iter--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		minus = 1;
	}
	while (iter >= minus)
	{
		res[iter--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
