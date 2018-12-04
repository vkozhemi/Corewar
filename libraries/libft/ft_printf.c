/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:46:52 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/13 11:46:54 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_check_flag(const char *format, t_flag *flag)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->specs = 0;
	while (*format == '#' || *format == ' ' || *format == '0' || *format == '-'
		|| *format == '+')
	{
		if (*format == '#')
			flag->sharp = 1;
		else if (*format == ' ' && !flag->specs)
			flag->specs = ' ';
		else if (*format == '0')
			flag->zero = 1;
		else if (*format == '-')
			flag->minus = 1;
		else if (*format == '+')
			flag->specs = '+';
		format++;
	}
	return (format);
}

const char	*ft_check_width(const char *format, t_flag *flag)
{
	if (*format == '*' && format++ && (flag->width = va_arg(flag->ap, int)))
	{
		if (flag->width < 0 && ++flag->minus)
			flag->width = ABS((flag->width));
	}
	else
	{
		flag->width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	if (*format == '.' && format++)
	{
		if (*format == '*')
		{
			flag->prec = va_arg(flag->ap, int);
			return (++format);
		}
		flag->prec = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
	}
	else
		flag->prec = -1;
	return (format);
}

static int	ft_slen(char const *s)
{
	int i;

	i = 0;
	while (*s != '%' && *s++)
		i++;
	return (i);
}

static int	ft_putfmt(const char **str)
{
	int i;

	i = ft_slen(*str);
	write(1, *str, i);
	*str += i;
	return (i);
}

int			ft_printf(const char *format, ...)
{
	t_flag flag;

	flag.i = 0;
	va_start(flag.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_check_flag(++format, &flag);
			format = ft_check_width(format, &flag);
			pf_conver(&format, &flag);
			format++;
		}
		else
			flag.i += ft_putfmt(&format);
	}
	va_end(flag.ap);
	return (flag.i);
}
