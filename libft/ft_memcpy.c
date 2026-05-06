/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:43:30 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:48:08 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;

	dest_str = (char *) dest;
	src_str = (char *) src;
	if (!dest && !src)
		return (0);
	while (n--)
		*dest_str++ = *src_str++;
	return (dest);
}
