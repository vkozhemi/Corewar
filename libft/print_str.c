/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_modifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:09:33 by msakovyc          #+#    #+#             */
/*   Updated: 2018/05/21 13:09:35 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		putstr_u(wchar_t *s)
{
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	while (s && s[i])
		bytes += print_unicode(s[i++]);
	return (bytes);
}

int		putnstr_u(wchar_t *s, int n)
{
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	while (s && s[i] && (bytes + counter_c(s[i])) <= n)
		bytes += print_unicode(s[i++]);
	if (bytes == 0 && n)
		bytes += print_unicode(s[i++]);
	return (bytes);
}

int		counter_c(wchar_t c)
{
	int size;

	size = count_base(c, 2);
	if (size <= 7)
		return (1);
	else if (size <= 11)
		return (2);
	else if (size <= 16)
		return (3);
	else
		return (4);
}

int		print_u_s(t_frmt frmt, va_list ap)
{
	wchar_t	*s;
	int		bytes;

	s = va_arg(ap, wchar_t*);
	if (!s)
		s = L"(null)";
	if (frmt.minus)
	{
		bytes = (frmt.prec && frmt.max <= count_unicode(s, -1)) ?
			putnstr_u(s, count_unicode(s, frmt.max)) : putstr_u(s);
		return (bytes + repeat_char(' ', frmt.min - bytes));
	}
	else if (frmt.zero || frmt.plus || frmt.sharp)
	{
		bytes = (frmt.prec && frmt.max <= count_unicode(s, -1)) ?
			count_unicode(s, frmt.max) : count_unicode(s, -1);
		return (repeat_char((frmt.zero) ? '0' : ' ', frmt.min - bytes)
			+ putnstr_u(s, bytes));
	}
	else if (frmt.prec && frmt.max <= count_unicode(s, -1))
		return (repeat_char(' ', frmt.min - count_unicode(s, frmt.max)) +
			putnstr_u(s, frmt.max));
	else
		return (repeat_char(' ', frmt.min - count_unicode(s, -1))
			+ putstr_u(s));
}

int		print_s(t_frmt frmt, va_list ap)
{
	char	*s;
	int		bytes;

	s = va_arg(ap, char*);
	if (!s)
		s = "(null)";
	if (frmt.minus)
	{
		bytes = (frmt.prec && frmt.max <= ft_strlen(s)) ?
			ft_putnstr(s, frmt.max) : ft_putstr(s);
		return (bytes + repeat_char(' ', frmt.min - bytes));
	}
	else if (frmt.plus || frmt.zero || frmt.sharp || frmt.space)
	{
		bytes = (frmt.prec && frmt.max <= ft_strlen(s)) ?
			frmt.max : ft_strlen(s);
		return (repeat_char((frmt.zero) ? '0' : ' ', frmt.min - bytes)
			+ ft_putnstr(s, bytes));
	}
	else if (frmt.prec && frmt.max <= ft_strlen(s))
		return (repeat_char(' ', frmt.min - frmt.max)
			+ ft_putnstr(s, frmt.max));
	else
		return (repeat_char(' ', frmt.min - ft_strlen(s)) + ft_putstr(s));
}
