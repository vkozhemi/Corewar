/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:29:03 by msakovyc          #+#    #+#             */
/*   Updated: 2018/06/04 17:29:05 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		print_unicode_c(va_list ap)
{
	wchar_t c;

	c = va_arg(ap, wchar_t);
	return (print_unicode(c));
}

int		print_c(t_frmt frmt, intmax_t c)
{
	if (frmt.minus)
		return (ft_putchar(c) + repeat_char(' ', frmt.min - 1));
	else if (frmt.plus || frmt.zero || frmt.sharp || frmt.space)
		return (repeat_char((frmt.zero) ? '0' : ' ', frmt.min - 1)
			+ ft_putchar(c));
	else
		return (repeat_char(' ', frmt.min - 1) + ft_putchar(c));
}

int		print_d(t_frmt frmt, intmax_t d)
{
	int		bytes;
	int		minus;

	minus = 0;
	bytes = 0;
	if (frmt.prec && !frmt.max && !d)
		return (repeat_char((frmt.zero ? '0' : ' '), frmt.min));
	if (d < 0)
		minus = 1;
	if (frmt.minus)
	{
		if (minus || frmt.plus)
			bytes += ft_putchar(minus ? '-' : '+');
		bytes += (frmt.prec && frmt.max > count_base(d, 10)) ?
			repeat_char('0', frmt.max - count_base(d, 10)) : 0;
		bytes += print_base(d, 10, 0, 0);
		if ((frmt.prec && frmt.max < frmt.min) || !frmt.prec)
			bytes += repeat_char(' ', frmt.min - bytes);
		return (bytes);
	}
	if (frmt.zero || frmt.sharp || frmt.space)
		return (print_d2(frmt, d, bytes, minus));
	return (print_d3(frmt, d, bytes, minus));
}

int		print_d2(t_frmt frmt, intmax_t d, int bytes, int minus)
{
	int sign;

	sign = 0;
	if (frmt.space && !minus && !frmt.plus)
		bytes += ft_putchar(' ');
	if ((frmt.plus || minus) && frmt.zero && !frmt.prec)
		bytes += ft_putchar(minus ? '-' : '+');
	sign = bytes ? bytes : minus;
	if (frmt.prec)
		bytes += repeat_char(' ', frmt.min - sign - ((frmt.max >
			count_base(d, 10) - sign) ? frmt.max : count_base(d, 10)));
	else
		bytes += repeat_char((frmt.zero) ? '0' : ' ', frmt.min -
			count_base(d, 10) - sign);
	if (((frmt.plus || minus) && !frmt.zero) || (frmt.prec && minus))
		bytes += ft_putchar(minus ? '-' : '+');
	bytes += (frmt.prec) ? repeat_char('0', frmt.max -
		count_base(d, 10)) : 0;
	bytes += print_base(d, 10, 0, 0);
	return (bytes);
}

int		print_d3(t_frmt frmt, intmax_t d, int bytes, int minus)
{
	if (frmt.plus)
	{
		bytes = repeat_char(' ', frmt.min - 1 - ((frmt.max >
			count_base(d, 10) - 1) ? frmt.max : count_base(d, 10)));
		bytes += ft_putchar(minus ? '-' : '+');
		bytes += repeat_char('0', frmt.max - count_base(d, 10)) +
			print_base(d, 10, 0, 0);
		return (bytes);
	}
	bytes += repeat_char(' ', frmt.min - minus - (frmt.max > count_base(d, 10)
		? frmt.max : count_base(d, 10)));
	if (minus)
		ft_putchar('-');
	bytes += repeat_char('0', frmt.max - count_base(d, 10));
	return (bytes + minus + print_base(d, 10, 0, 0));
}
