/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 17:03:18 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/28 17:03:19 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_converll(const char **format, t_flag *f, char *buff)
{
	(*format)++;
	if (**format == 'd' || **format == 'i')
		pf_number(pf_putllnbr(va_arg(f->ap, long int), buff, f), f);
	else if (**format == 'o')
		pf_octal(pf_putllx(va_arg(f->ap, long int), 3, buff, f->sharp), f);
	else if (**format == 'b')
		pf_octal(pf_putllx(va_arg(f->ap, long int), 1, buff, f->sharp), f);
	else if (**format == 'x')
		pf_hex(pf_putllx(va_arg(f->ap, long int), 4, buff, f->sharp), f);
	else if (**format == 'u' || **format == 'U')
		pf_unsigned(pf_putu(va_arg(f->ap, unsigned long long int), buff), f);
	else if (**format == 'D')
		pf_number(pf_putlnbr(va_arg(f->ap, long int), buff, f), f);
	else if (**format == 'X')
		pf_hex(pf_putuplx(va_arg(f->ap, long int), 4, buff, f->sharp), f);
	else if (**format == 'O')
		pf_octal(pf_putlx(va_arg(f->ap, long int), 3, buff, f->sharp), f);
}

static void		ft_converl(const char **format, t_flag *f, char *buff)
{
	(*format)++;
	if (**format == 'd' || **format == 'i' || **format == 'D')
		pf_number(pf_putlnbr(va_arg(f->ap, long int), buff, f), f);
	else if (**format == 'o' || **format == 'O')
		pf_octal(pf_putlx(va_arg(f->ap, long int), 3, buff, f->sharp), f);
	else if (**format == 'b')
		pf_octal(pf_putlx(va_arg(f->ap, long int), 1, buff, f->sharp), f);
	else if (**format == 'x')
		pf_hex(pf_putlx(va_arg(f->ap, long int), 4, buff, f->sharp), f);
	else if (**format == 'u' || **format == 'U')
		pf_unsigned(pf_putu(va_arg(f->ap, unsigned long int), buff), f);
	else if (**format == 'X')
		pf_hex(pf_putuplx(va_arg(f->ap, long int), 4, buff, f->sharp), f);
	else if (**format == 'p')
		pf_hex(pf_putaddr((ULI)va_arg(f->ap, void *), buff), f);
	else if (**format == 'c')
		pf_unic(va_arg(f->ap, unsigned int), f);
	else if (**format == 's')
		pf_unis(va_arg(f->ap, unsigned int*), f);
	else if (**format == 'l')
		ft_converll(format, f, buff);
}

static void		ft_conver_plus(const char **format, t_flag *f, char *buff)
{
	if (**format == 'U')
		pf_unsigned(pf_putu(va_arg(f->ap, unsigned long int), buff), f);
	else if (**format == 'D')
		pf_number(pf_putlnbr(va_arg(f->ap, long int), buff, f), f);
	else if (**format == 'O')
		pf_octal(pf_putlx(va_arg(f->ap, long int), 3, buff, f->sharp), f);
	else if (**format == 'l' || **format == 'z')
		ft_converl(format, f, buff);
	else if (**format == 'j')
		ft_converll(format, f, buff);
	else if (**format == 'h')
		pf_converh(format, f, buff);
}

static void		ft_conver_digital(const char **format, t_flag *f)
{
	char buff[30];

	ft_memset(buff, 0, 31);
	if (**format == 'd' || **format == 'i')
		pf_number(pf_putnbr(va_arg(f->ap, int), buff, f), f);
	else if (**format == 'o')
		pf_octal(pf_putx(va_arg(f->ap, int), 3, buff, f->sharp), f);
	else if (**format == 'b')
		pf_octal(pf_putx(va_arg(f->ap, int), 1, buff, f->sharp), f);
	else if (**format == 'p')
		pf_hex(pf_putaddr((unsigned long int)va_arg(f->ap, void *), buff), f);
	else if (**format == 'x')
		pf_hex(pf_putx(va_arg(f->ap, int), 4, buff, f->sharp), f);
	else if (**format == 'X')
		pf_hex(pf_putupx(va_arg(f->ap, int), 4, buff, f->sharp), f);
	else if (**format == 'u')
		pf_unsigned(pf_putu(va_arg(f->ap, unsigned int), buff), f);
	else
		ft_conver_plus(format, f, buff);
}

void			pf_conver(const char **format, t_flag *f)
{
	if (**format == 's')
		pf_string(va_arg(f->ap, char*), f);
	else if (**format == 'c')
		pf_char((char)(va_arg(f->ap, int)), f);
	else if (**format == '%')
		pf_char('%', f);
	else if (**format == 'C')
		pf_unic(va_arg(f->ap, unsigned int), f);
	else if (**format == 'S')
		pf_unis(va_arg(f->ap, unsigned int*), f);
	else
		ft_conver_digital(format, f);
}
