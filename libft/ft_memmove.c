/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:40:03 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:48:12 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;

	dest_str = (char *)dest;
	src_str = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
			*dest_str++ = *src_str++;
	}
	else if (dest > src)
	{
		dest_str += n - 1;
		src_str += n -1;
		while (n--)
			*dest_str-- = *src_str--;
	}
	return (dest);
}
