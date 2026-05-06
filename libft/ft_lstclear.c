/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:45:47 by lrouchon          #+#    #+#             */
/*   Updated: 2026/02/16 15:09:05 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (lst && *lst && del)
	{
		ft_lstiter(*lst, del);
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*lst = 0;
	}
}
