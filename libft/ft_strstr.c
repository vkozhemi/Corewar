/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:04:45 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/27 16:45:53 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, char *needle)
{
	char	*temp_needle;
	int		i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	temp_needle = (char *)needle;
	while (*haystack)
	{
		needle = temp_needle;
		i = 0;
		if (*(haystack) == needle[0])
			while (*(haystack + i) == *needle)
			{
				i++;
				needle++;
				if (*needle == '\0')
					return ((char *)haystack);
			}
		haystack++;
	}
	return (0);
}
