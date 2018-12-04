/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:25:55 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/28 18:39:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_fill(char **box, char const *s, char c)
{
	int		len;
	char	**rat;

	rat = box;
	len = 0;
	while (*s)
		if (*s == c)
		{
			*box++ = ft_strsub((s - len), 0, len);
			s = ft_skip_char(s, c);
			len = 0;
		}
		else
		{
			len++;
			s++;
		}
	if (len)
		*box = ft_strsub((s - len), 0, len);
	return (rat);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**box;

	if (!s)
		return (NULL);
	s = ft_skip_char(s, c);
	box = (char **)ft_memalloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!box)
		return (NULL);
	box = ft_fill(box, s, c);
	return (box);
}
