/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:24:07 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:47:27 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	char				*s_dest;

	s_dest = (char *) s;
	i = 0;
	while (i < n)
	{
		s_dest[i] = '\0';
		i++;
	}
}
