/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:57:16 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/29 11:05:31 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if (!(tmp = (void *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if ((tmp->content = (void *)ft_memalloc(content_size)))
		{
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		else
			tmp->content_size = 0;
	}
	else
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	tmp->next = NULL;
	return (tmp);
}
