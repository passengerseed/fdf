/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:46:00 by lrouchon          #+#    #+#             */
/*   Updated: 2026/02/15 17:51:46 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*newcontent;

	newlist = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		newcontent = f(lst->content);
		if (!newcontent)
			return (ft_lstclear(&newlist, del), (void *)0);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			return (ft_lstclear(&newlist, del), (void *)0);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
