/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_puox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:30:46 by msakovyc          #+#    #+#             */
/*   Updated: 2018/06/04 17:30:48 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		print_p(t_frmt frmt, va_list ap)
{
	unsigned long int	u;
	int					bytes;
	int					ox;

	ox = 2;
	bytes = 0;
	u = va_arg(ap, unsigned long int);
	if (frmt.minus)
	{
		bytes += ft_putstr("0x");
		bytes += repeat_char('0', (count_ubase(u, 16) < frmt.max) ?
			frmt.max - count_ubase(u, 16) : 0);
		bytes += ((!u && frmt.prec && !frmt.max) ?
			0 : print_ubase(u, 16, 0, 0));
		return (bytes + repeat_char(' ', frmt.min - bytes));
	}
	else if (frmt.sharp || frmt.plus || frmt.zero || frmt.space)
		return (print_p2(frmt, u, ox));
	bytes += repeat_char(' ', frmt.min - (frmt.max > count_ubase(u, 16) ?
		frmt.max : count_ubase(u, 16)) - 2);
	bytes += ft_putstr("0x");
	bytes += repeat_char('0', frmt.max - count_ubase(u, 16));
	return (bytes + ((!u && frmt.prec && !frmt.max)
		? 0 : print_ubase(u, 16, 0, 0)));
}

int		print_p2(t_frmt frmt, unsigned long int u, int ox)
{
	int				bytes;
	int				n;

	bytes = 0;
	n = frmt.max ? frmt.max : count_ubase(u, 16);
	if ((frmt.min <= n || !frmt.min || frmt.zero) && ((ox = 0) == 0))
		bytes += ft_putstr("0x");
	bytes += repeat_char((frmt.zero && (frmt.min < n || !frmt.max)) ?
		'0' : ' ', frmt.min - n - 2);
	(ox) ? bytes += ft_putstr("0x") : 0;
	if (frmt.max > count_ubase(u, 16))
		bytes += repeat_char('0', frmt.max - count_ubase(u, 16));
	return (bytes + ((!u && frmt.prec && !frmt.max) ?
		0 : print_ubase(u, 16, 0, 0)));
}

int		print_uox(t_frmt f, uintmax_t u)
{
	int				bytes;
	int				base;
	int				ox;

	bytes = 0;
	base = (f.modifier == 'o' || f.modifier == 'O') ? 8 : 16;
	(f.modifier == 'u' || f.modifier == 'U') ? base = 10 : 0;
	(f.modifier == 'b' || f.modifier == 'B') ? base = 2 : 0;
	if (f.prec && !f.max && !u && !(f.sharp && base == 8))
		return (repeat_char((f.zero ? '0' : ' '), f.min));
	ox = (f.sharp && base == 16) ? 2 : 0;
	(f.sharp && base == 8 && u) ? ox = 1 : 0;
	if (f.minus)
	{
		bytes += (ox == 1) ? ft_putchar('0') : 0;
		if (ox == 2)
			bytes += ft_putstr(STR);
		bytes += repeat_char('0', (count_ubase(u, base) < f.max)
			? f.max - count_ubase(u, base) : 0);
		bytes += print_ubase(u, base, 0, UPPER);
		return (bytes + repeat_char(' ', (bytes < f.min ?
			f.min - bytes : 0)));
	}
	return ((f.sharp || f.plus || f.zero || f.space) ?
		print_uox2(f, u, ox, base) : print_uox3(f, u, ox, base));
}

int		print_uox2(t_frmt f, uintmax_t u, int ox, int base)
{
	int bytes;
	int n;

	bytes = 0;
	n = (f.max > count_ubase(u, base)) ? f.max : count_ubase(u, base);
	n == f.max && base == 16 ? f.prec = 0 : 0;
	if (f.min <= n + ox || (f.zero && (!f.prec || f.min <= f.max)))
	{
		if (ox == 2 && u && !f.space && !f.plus && (!f.min || f.zero)
			&& !(ox = 0))
			bytes += ft_putstr(STR);
		if (ox == 1 && !f.space && !f.plus && (!f.min || f.zero) && !(ox = 0))
			bytes += ft_putchar('0');
	}
	bytes += repeat_char((f.zero && (f.min < n || !f.max)) ? '0' : ' ', f.min -
		n - ((!f.prec || f.max < count_ubase(u, base)) && f.sharp && base == 16
		&& u ? 2 : 0) - ((!f.prec || f.max < count_ubase(u, base)) && f.sharp
		&& base == 8 && u ? 1 : 0));
	if (ox && u != 0)
		bytes += (ox == 2) ? ft_putstr(STR) : ft_putchar('0');
	if (f.max > count_ubase(u, base))
		bytes += repeat_char('0', f.max - count_ubase(u, base) -
			(f.sharp && base == 8 && u ? 1 : 0));
	return (bytes + ((!u && base == 16 && f.prec && !f.max) ?
		0 : print_ubase(u, base, 0, UPPER)));
}

int		print_uox3(t_frmt f, uintmax_t u, int ox, int base)
{
	int bytes;

	bytes = 0;
	bytes += repeat_char(' ', f.min - (f.max > count_ubase(u, base) ?
		f.max : count_ubase(u, base)) - ox);
	if (ox && u != 0)
		bytes += (ox == 2) ? ft_putstr(STR) : ft_putchar('0');
	bytes += repeat_char('0', f.max - count_ubase(u, base));
	return (bytes + print_ubase(u, base, 0, UPPER));
}
