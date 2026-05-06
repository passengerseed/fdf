/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:17:36 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:49:19 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	s_dest;
	size_t	s_src;
	size_t	i;
	size_t	j;

	s_dest = ft_strlen(dest);
	s_src = ft_strlen(src);
	i = s_dest;
	j = 0;
	if (n < 1)
		return (n + s_src);
	while (src[j] && i < n - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (n < s_dest)
		return (n + s_src);
	return (s_dest + s_src);
}
