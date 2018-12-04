/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:18:34 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/24 11:18:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_space(int len)
{
	char	buff[len];
	char	*str;
	int		i;

	i = len;
	str = buff;
	while (i--)
		*str++ = ' ';
	write(1, buff, len);
}

static int	ft_puts(char const *s, int len)
{
	write(1, s, len);
	return (len);
}

void		pf_string(char *str, t_flag *flag)
{
	int len;

	if (!str)
	{
		write(1, "(null)", 6);
		flag->i += 6;
		return ;
	}
	len = ft_strlen(str);
	if (flag->prec >= 0 && flag->prec < len)
		len = flag->prec;
	if ((flag->width -= len) > 0)
	{
		if (flag->minus)
		{
			flag->i += ft_puts(str, len) + flag->width;
			ft_space(flag->width);
			return ;
		}
		ft_space(flag->width);
		flag->i += flag->width + ft_puts(str, len);
	}
	else
		flag->i += ft_puts(str, len);
}
