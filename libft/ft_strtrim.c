/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:48:44 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/28 16:00:20 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char		*strnew;
	size_t		len;
	size_t		lensrc;

	len = 0;
	if (!s)
		return (0);
	lensrc = ft_strlen(s) - 1;
	while ((*(s + len) == ' ' || *(s + len) == '\n' || *(s + len) == '\t')
		&& *(s + len))
		len++;
	while ((*(s + lensrc) == ' ' || *(s + lensrc) == '\n'
		|| *(s + lensrc) == '\t') && *(s + lensrc) && len < lensrc)
		lensrc--;
	strnew = (char *)malloc(sizeof(char) * (lensrc - len + 2));
	if (!strnew)
		return (0);
	ft_strncpy(strnew, (s + len), (lensrc - len + 1));
	strnew[lensrc - len + 1] = '\0';
	return (strnew);
}
