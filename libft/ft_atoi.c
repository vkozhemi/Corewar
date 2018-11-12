/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:11:01 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/26 22:11:51 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	result;
	int	minus;

	result = 0;
	minus = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (int)*str - '0';
		str++;
	}
	if (minus)
		return (-result);
	return (result);
}
