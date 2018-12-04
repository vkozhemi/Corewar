/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:09:51 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/29 14:31:12 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_overlong(char const *str, int min)
{
	int i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i++;
		str++;
		if (i > 18 && min == 1)
			return (-1);
		if (i > 18 && min == -1)
			return (0);
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int nb;
	int min;

	nb = 0;
	min = 1;
	while (*str == ' ' || *str == '\v' || *str == '\f' || *str == '\t'
			|| *str == '\r' || *str == '\n')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		min = -1;
	}
	if (ft_overlong(str, min) < 1)
		return (ft_overlong(str, min));
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * min);
}
