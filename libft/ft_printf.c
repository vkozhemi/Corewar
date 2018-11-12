/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 15:43:31 by msakovyc          #+#    #+#             */
/*   Updated: 2018/04/28 15:43:32 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	start_check(char *str, va_list ap, t_frmt *f)
{
	char *s;

	ft_bzero(f, 8 * sizeof(int) + 2 * sizeof(char));
	while ((ft_isdigit(str[f->i]) && str[f->i] != '0') || str[f->i] == '*')
		if (str[f->i] == '*' && ((f->i)++))
			f->min = va_arg(ap, int);
		else
			f->min = ft_atoi_ptr(str, &(f->i));
	while ((s = ft_strchr("#0-+ ", str[f->i])) != NULL)
	{
		if (*s == '#')
			f->sharp = 1;
		else if (*s == '0')
			f->zero = 1;
		else if (*s == '+')
			f->plus = 1;
		else if (*s == '-')
			f->minus = 1;
		else
			f->space = 1;
		if ((++(f->i)) && str[f->i] == '*' && ((f->i)++))
			f->min = va_arg(ap, int);
		else if (ft_isdigit(str[f->i]) && str[f->i] != '0')
			f->min = ft_atoi_ptr(str, &(f->i));
	}
}

void	finish_check(char *str, t_frmt *f)
{
	char *s;

	while ((s = ft_strchr("hljz", str[f->i])) != NULL)
	{
		f->spec = (str[f->i + 1] == str[f->i] && ((f->i)++)) ?
			ft_toupper(*s) : *s;
		(f->i)++;
	}
	if ((s = ft_strchr("nsSpdDioOuUxXbBcC%", str[f->i])) != NULL && ((f->i)++))
		f->modifier = *s;
	if (f->min < 0 && (f->min *= -1) > 0)
		f->minus = 1;
}

void	check(char *str, va_list ap, t_frmt *f)
{
	start_check(str, ap, f);
	while (str[f->i] == '.' && (f->prec = 1))
		if ((++(f->i)) && str[f->i] == '*' && ((f->i)++))
		{
			f->max = va_arg(ap, int);
			if (f->max < 0 && !(f->max = 0))
				f->prec = 0;
		}
		else if (ft_isdigit(str[f->i]) || str[f->i] == '-')
		{
			f->max = ft_atoi_ptr(str, &(f->i));
			if (f->max < 0 && (f->min = f->max * -1))
			{
				f->minus = 1;
				f->prec = 0;
				f->max = 0;
			}
		}
	finish_check(str, f);
}

int		ft_printf(char *str, ...)
{
	int		start;
	t_frmt	frmt;
	va_list	ap;

	ft_bzero(&frmt, sizeof(t_frmt));
	va_start(ap, str);
	start = 0;
	if (!ft_strcmp(str, "%"))
		return (0);
	while (str[frmt.i] && (start = frmt.i) == frmt.i)
		if (str[frmt.i] == '%' && (++frmt.i))
		{
			check(str, ap, &frmt);
			frmt.bytes += print(str, ap, &frmt);
		}
		else
		{
			while (str[frmt.i] && str[frmt.i] != '%')
				frmt.i++;
			frmt.bytes += frmt.i - start;
			ft_putnstr(str + start, frmt.i - start);
		}
	va_end(ap);
	return (frmt.bytes);
}
