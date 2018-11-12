/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:55:29 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/29 18:57:42 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_putstr(char const *s)
{
	int		i;

	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}
