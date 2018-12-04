/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:48:08 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/26 14:48:10 by vkaidans         ###   ########.fr       */
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
	flag->prec -= ft_strlen(str);
	flag->prec = (flag->prec < 0) ? 0 : flag->prec;
	if ((flag->width -= (flag->prec + ft_strlen(str))) > 0)
	{
		if (flag->minus)
		{
			ft_space(flag->prec, '0');
			flag->prec += pf_puts(str);
			flag->i += flag->prec;
			flag->i += flag->width;
			ft_space(flag->width, ' ');
			return ;
		}
		ft_space(flag->width, ' ');
		ft_space(flag->prec, '0');
		flag->width += flag->prec + pf_puts(str);
		flag->i += flag->width;
		return ;
	}
	ft_space(flag->prec, '0');
	flag->i += pf_puts(str);
	flag->i += flag->prec;
}

void		pf_hex(char *str, t_flag *flag)
{
	if (flag->prec >= 0)
		ft_precision(str, flag);
	else if ((flag->width -= ft_strlen(str)) > 0)
	{
		if (flag->minus)
		{
			flag->i += pf_puts(str) + flag->width;
			ft_space(flag->width, ' ');
		}
		else
		{
			if (flag->sharp && flag->zero)
			{
				flag->i += 2;
				write(1, str, 2);
				str += 2;
			}
			ft_space(flag->width, (flag->zero) ? '0' : ' ');
			flag->width += pf_puts(str);
			flag->i += flag->width;
		}
	}
	else
		flag->i += pf_puts(str);
}
