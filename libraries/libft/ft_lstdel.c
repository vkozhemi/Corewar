/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 10:25:36 by vkaidans          #+#    #+#             */
/*   Updated: 2018/03/29 11:13:30 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list *tmp;

	while (*alst)
	{
		tmp = *alst;
		*alst = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
	*alst = NULL;
}
