/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:54:55 by msakovyc          #+#    #+#             */
/*   Updated: 2018/06/04 17:54:57 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		print(char *str, va_list ap, t_frmt *frmt)
{
	if (frmt->modifier == 'C')
	{
		if (MB_CUR_MAX == 1)
			frmt->modifier = 'c';
		else
			return (print_unicode_c(ap));
	}
	if (frmt->modifier == 'S')
	{
		if (MB_CUR_MAX == 1)
			frmt->modifier = 's';
		else
			return (print_u_s(*frmt, ap));
	}
	if (frmt->modifier == 'c')
	{
		if (frmt->spec == 'l')
			return (print_unicode_c(ap));
		return (print_c(*frmt, (char)va_arg(ap, int)));
	}
	if (frmt->modifier == 'S')
		return (MB_CUR_MAX == 1 ? print_s(*frmt, ap) : print_u_s(*frmt, ap));
	else if (frmt->modifier == '%')
		return (print_c(*frmt, (int)'%'));
	return (print2(str, ap, frmt));
}

int		print2(char *str, va_list ap, t_frmt *frmt)
{
	intmax_t	d;

	if (frmt->modifier == 's')
		return (frmt->spec == 'l' ? print_u_s(*frmt, ap) : print_s(*frmt, ap));
	if (frmt->modifier == 'd' || frmt->modifier == 'i')
	{
		if (frmt->spec == 'h')
			d = (short)va_arg(ap, int);
		else if (frmt->spec == 'H')
			d = (char)va_arg(ap, int);
		else if (frmt->spec == 'l')
			d = va_arg(ap, long int);
		else if (frmt->spec == 'L')
			d = va_arg(ap, long long int);
		else if (frmt->spec == 'z')
			d = va_arg(ap, size_t);
		else if (frmt->spec == 'j')
			d = va_arg(ap, intmax_t);
		else
			d = va_arg(ap, int);
		return (print_d(*frmt, d));
	}
	else if (frmt->modifier == 'D')
		return (print_d(*frmt, va_arg(ap, long int)));
	return (print3(str, ap, frmt));
}

int		print3(char *str, va_list ap, t_frmt *frmt)
{
	uintmax_t	u;

	if (frmt->modifier == 'u' || frmt->modifier == 'o' ||
	frmt->modifier == 'x' || frmt->modifier == 'X' || frmt->modifier == 'b')
	{
		if (frmt->spec == 'h')
			u = (unsigned short)va_arg(ap, unsigned int);
		else if (frmt->spec == 'H')
			u = (unsigned char)va_arg(ap, unsigned int);
		else if (frmt->spec == 'l')
			u = va_arg(ap, unsigned long int);
		else if (frmt->spec == 'L')
			u = va_arg(ap, unsigned long long int);
		else if (frmt->spec == 'z')
			u = va_arg(ap, size_t);
		else if (frmt->spec == 'j')
			u = va_arg(ap, uintmax_t);
		else
			u = va_arg(ap, unsigned int);
		return (print_uox(*frmt, u));
	}
	else if (frmt->modifier == 'U' || frmt->modifier == 'O' ||
		frmt->modifier == 'B')
		return (print_uox(*frmt, va_arg(ap, unsigned long int)));
	return (print4(str, ap, frmt));
}

int		print4(char *str, va_list ap, t_frmt *frmt)
{
	if (frmt->modifier == 'n')
		return (print_d(*frmt, frmt->bytes));
	else if (frmt->modifier == 'p')
		return (print_p(*frmt, ap));
	else
		return (print_c(*frmt, str[(frmt->i)++]));
	return (0);
}
