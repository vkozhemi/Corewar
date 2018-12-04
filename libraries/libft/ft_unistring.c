/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:19:39 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/27 18:19:41 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_space(int len)
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

static int		ft_puts(unsigned char *s, int len)
{
	write(1, s, len);
	return (len);
}

static int		ft_slen(unsigned int *str)
{
	int len;

	len = 0;
	if (str)
		while (*str++)
			len++;
	return (len);
}

static void		ft_putunis(unsigned char *str, int len, t_flag *flag)
{
	if (flag->prec >= 0 && flag->prec < len)
		len = flag->prec;
	if ((flag->width -= len) > 0)
	{
		if (flag->minus)
		{
			flag->i += (ft_puts(str, len) + flag->width);
			ft_space(flag->width);
		}
		else
		{
			ft_space(flag->width);
			flag->i += (flag->width + ft_puts(str, len));
		}
	}
	else
		flag->i += (ft_puts(str, len));
}

void			pf_unis(unsigned int *str, t_flag *flag)
{
	unsigned char	buff[ft_slen(str) << 2];
	unsigned char	*rat;
	int				size;
	int				len;

	if (!str)
	{
		write(1, "(null)", 6);
		flag->i += 6;
		return ;
	}
	rat = buff;
	size = 0;
	while (*str)
	{
		len = pf_uniparser(*str, rat);
		rat += len;
		size += len;
		str++;
	}
	ft_putunis(buff, size, flag);
}
