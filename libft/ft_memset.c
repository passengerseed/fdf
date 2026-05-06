/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:28:54 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/13 17:00:05 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t		i;
	char		*c_dest;

	c_dest = (char *) dest;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c;
		i++;
	}
	return (c_dest);
}
