/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsilva-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:38:47 by bsilva-c          #+#    #+#             */
/*   Updated: 2022/11/28 15:05:26 by bsilva-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		next_node = node->next;
		ft_lstdelone(node, del);
		node = next_node;
	}
	*lst = NULL;
}
