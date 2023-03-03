/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:00:00 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/28 15:06:14 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*next_node;

	if (!lst || !f || !del)
		return (0);
	list = ft_lstnew(f(lst->content));
	if (!list)
		return (0);
	lst = lst->next;
	next_node = list;
	while (lst)
	{
		next_node = ft_lstnew(f(lst->content));
		if (!next_node)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, next_node);
		lst = lst->next;
	}
	return (list);
}
