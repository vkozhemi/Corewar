/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:19:49 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/30 21:09:39 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *begin;

	begin = NULL;
	if (lst && f)
	{
		res = f(lst);
		begin = res;
		lst = lst->next;
		while (lst)
		{
			res->next = f(lst);
			res = res->next;
			lst = lst->next;
		}
	}
	return (begin);
}
