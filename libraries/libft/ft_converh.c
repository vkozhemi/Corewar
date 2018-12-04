/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:09:05 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/28 19:09:10 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_converhh(const char **format, t_flag *f, char *buff)
{
	(*format)++;
	if (**format == 'd' || **format == 'i')
		pf_number(pf_putnbr((char)va_arg(f->ap, int), buff, f), f);
	else if (**format == 'D')
		pf_number(pf_putnbr(va_arg(f->ap, int), buff, f), f);
	else if (**format == 'u')
		pf_unsigned(pf_putu((UC)va_arg(f->ap, unsigned int), buff), f);
	else if (**format == 'U')
		pf_unsigned(pf_putu((USI)va_arg(f->ap, unsigned int), buff), f);
	else if (**format == 'o')
		pf_octal(pf_putx((UC)va_arg(f->ap, int), 3, buff, f->sharp), f);
	else if (**format == 'b')
		pf_octal(pf_putx((UC)va_arg(f->ap, int), 1, buff, f->sharp), f);
	else if (**format == 'O')
		pf_octal(pf_putx((USI)va_arg(f->ap, long int), 3, buff, f->sharp), f);
	else if (**format == 'x')
		pf_hex(pf_putx((UC)va_arg(f->ap, int), 4, buff, f->sharp), f);
	else if (**format == 'X')
		pf_hex(pf_putupx((UC)va_arg(f->ap, int), 4, buff, f->sharp), f);
}

void			pf_converh(const char **format, t_flag *f, char *buff)
{
	(*format)++;
	if (**format == 'd' || **format == 'i')
		pf_number(pf_putnbr((short int)va_arg(f->ap, int), buff, f), f);
	else if (**format == 'D')
		pf_number(pf_putnbr(va_arg(f->ap, int), buff, f), f);
	else if (**format == 'u')
		pf_unsigned(pf_putu((USI)va_arg(f->ap, unsigned int), buff), f);
	else if (**format == 'U')
		pf_unsigned(pf_putu(va_arg(f->ap, unsigned long int), buff), f);
	else if (**format == 'o')
		pf_octal(pf_putx(va_arg(f->ap, int), 3, buff, f->sharp), f);
	else if (**format == 'b')
		pf_octal(pf_putx(va_arg(f->ap, int), 1, buff, f->sharp), f);
	else if (**format == 'O')
		pf_octal(pf_putx((int)va_arg(f->ap, long int), 3, buff, f->sharp), f);
	else if (**format == 'x')
		pf_hex(pf_putx(va_arg(f->ap, int), 4, buff, f->sharp), f);
	else if (**format == 'X')
		pf_hex(pf_putupx(va_arg(f->ap, int), 4, buff, f->sharp), f);
	else if (**format == 'h')
		ft_converhh(format, f, buff);
}
