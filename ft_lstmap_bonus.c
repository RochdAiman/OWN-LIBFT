/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:32:41 by arochd            #+#    #+#             */
/*   Updated: 2025/10/22 15:32:43 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_head;
	void	*new_content;
	t_list	*tail;

	new_head = NULL;
	tail = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		if (!new_head)
			new_head = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		lst = lst->next;
	}
	return (new_head);
}
