/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unichar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:19:10 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/27 18:19:11 by vkaidans         ###   ########.fr       */
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

void		pf_unic(UI v, t_flag *flag)
{
	int				len;
	unsigned char	buff[4];

	len = pf_uniparser(v, buff);
	if ((flag->width -= len) > 0)
	{
		if (flag->minus)
		{
			flag->i += len + flag->width;
			write(1, buff, len);
			ft_space(flag->width);
		}
		else
		{
			ft_space(flag->width);
			write(1, buff, len);
			flag->i += flag->width + len;
		}
	}
	else
	{
		flag->i += len;
		write(1, buff, len);
	}
}
