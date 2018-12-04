/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:35:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/05/24 12:35:58 by vkaidans         ###   ########.fr       */
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

void		pf_char(char c, t_flag *flag)
{
	if (--(flag->width) > 0)
	{
		if (flag->minus)
		{
			flag->i += pf_putc(c) + flag->width;
			ft_space(flag->width);
		}
		else
		{
			ft_space(flag->width);
			flag->width += pf_putc(c);
			flag->i += flag->width;
		}
	}
	else
		flag->i += pf_putc(c);
}
