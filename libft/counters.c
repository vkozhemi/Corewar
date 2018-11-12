/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:40:58 by msakovyc          #+#    #+#             */
/*   Updated: 2018/06/04 17:41:01 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		repeat_char(char c, int n)
{
	int i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i++ < n)
		ft_putchar(c);
	return (i - 1);
}

int		count_ubase(uintmax_t n, int base)
{
	int bytes;

	bytes = 0;
	while (n >= (uintmax_t)base)
	{
		n /= base;
		bytes++;
	}
	bytes++;
	return (bytes);
}

int		count_base(intmax_t n, int base)
{
	int bytes;

	bytes = 0;
	if (n == -9223372036854775807 - 1 && base == 10)
		return (19);
	if (n < 0)
		n *= -1;
	while (n >= base)
	{
		n /= base;
		bytes++;
	}
	bytes++;
	return (bytes);
}

int		print_base(intmax_t n, int base, int bytes, int upper)
{
	if (n == -9223372036854775807 - 1 && base == 10)
		return (ft_putstr("9223372036854775808"));
	if (n < 0)
		n *= -1;
	if (n >= base)
		bytes = print_base(n / base, base, bytes, upper);
	if (n % base > 9)
	{
		if (upper)
			ft_putchar(n % base + 'A' - 10);
		else
			ft_putchar(n % base + 'a' - 10);
	}
	else
		ft_putchar(n % base + '0');
	bytes++;
	return (bytes);
}

int		print_ubase(uintmax_t n, int base, int bytes, int upper)
{
	if (n >= (uintmax_t)base)
		bytes = print_ubase(n / base, base, bytes, upper);
	if (n % base > 9)
	{
		if (upper)
			ft_putchar(n % base + 'A' - 10);
		else
			ft_putchar(n % base + 'a' - 10);
	}
	else
		ft_putchar(n % base + '0');
	bytes++;
	return (bytes);
}
