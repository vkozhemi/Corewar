/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 19:03:13 by vkorniie          #+#    #+#             */
/*   Updated: 2018/04/02 13:19:31 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static int		ft_checker(const char *s, int l, char c, char **p)
{
	int i;
	int letters;
	int word;

	i = 0;
	letters = 0;
	word = 0;
	while (s[i] != '\0' && l)
	{
		if (s[i] != c)
		{
			if (s[i + 1] == '\0' || s[i + 1] == c)
			{
				p[word] = (char *)malloc(sizeof(char) * letters + 1);
				if (p[word] == NULL)
					return (0);
				letters = -1;
				word++;
				l--;
			}
			letters++;
		}
		i++;
	}
	return (1);
}

static void		copy(const char *s, int l, char c, char **p)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] && j < l)
	{
		if (s[i] != c)
		{
			p[j][k] = s[i];
			k++;
			if (s[i + 1] == '\0' || s[i + 1] == c)
			{
				p[j][k] = '\0';
				k = 0;
				j++;
			}
		}
		i++;
	}
	p[j] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	p = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (p == NULL)
		return (0);
	if (ft_checker(s, count_words(s, c), c, p))
	{
		copy(s, count_words(s, c), c, p);
		return (p);
	}
	return (0);
}
