/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:58:00 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/29 10:00:10 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	len = ft_strlen(s) - 1;
	if (*s)
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
	if ((str = ft_strsub(s, 0, len + 1)))
		return (str);
	return (NULL);
}
