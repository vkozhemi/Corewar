/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:23:11 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/24 12:23:13 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_space(int len, char c)
{
	char	buff[len];
	char	*str;

	str = buff;
	while (len--)
		*str++ = c;
	write(1, buff, sizeof(buff));
}

static void	ft_precision(char *str, t_flag *flag)
{
	if (*str == '0')
		*str = '\0';
	flag->prec = ((flag->prec -= ft_strlen(str)) < 0) ? 0 : flag->prec;
	if ((flag->width -= (flag->prec + ft_strlen(str))) > 0)
	{
		if (flag->minus)
		{
			if (flag->specs)
				flag->i += pf_putc(flag->specs);
			ft_space(flag->prec, '0');
			flag->i += flag->prec + pf_puts(str) + flag->width;
			ft_space(flag->width, ' ');
			return ;
		}
		ft_space(flag->width, ' ');
		if (flag->specs)
			flag->i += pf_putc(flag->specs);
		ft_space(flag->prec, '0');
		flag->i += flag->width + flag->prec + pf_puts(str);
		return ;
	}
	if (flag->specs)
		flag->i += pf_putc(flag->specs);
	ft_space(flag->prec, '0');
	flag->i += pf_puts(str) + flag->prec;
}

void		pf_number(char *str, t_flag *flag)
{
	(flag->specs) ? flag->width-- : 0;
	if (flag->prec >= 0)
		ft_precision(str, flag);
	else if ((flag->width -= ft_strlen(str)) > 0)
	{
		if (flag->zero && flag->specs)
			flag->i += pf_putc(flag->specs);
		if (!flag->minus)
			ft_space(flag->width, (flag->zero) ? '0' : ' ');
		if (!flag->zero && flag->specs)
			flag->i += pf_putc(flag->specs);
		flag->i += flag->width + pf_puts(str);
		if (flag->minus)
			ft_space(flag->width, ' ');
	}
	else
	{
		if (flag->specs)
			flag->i += pf_putc(flag->specs);
		flag->i += pf_puts(str);
	}
}
