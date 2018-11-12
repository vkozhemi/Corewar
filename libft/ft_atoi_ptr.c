/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 18:18:31 by msakovyc          #+#    #+#             */
/*   Updated: 2018/05/27 18:18:32 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_ptr(const char *str, int *i)
{
	int	result;
	int	minus;

	result = 0;
	minus = 0;
	while (str[*i] == ' ' || (str[*i] > 8 && str[*i] < 14))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			minus = 1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (int)str[*i] - '0';
		(*i)++;
	}
	if (minus)
		return (-result);
	return (result);
}
