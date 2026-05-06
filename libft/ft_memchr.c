/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:46:59 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:47:58 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_buf;

	c_buf = (unsigned char *) buf;
	i = 0;
	while (i < n)
	{
		if (c_buf[i] == (unsigned char)c)
			return (&c_buf[i]);
		i++;
	}
	return (0);
}
