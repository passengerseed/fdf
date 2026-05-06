/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:17:22 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:48:05 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_str;
	unsigned char	*s2_str;

	i = 0;
	s1_str = (unsigned char *) s1;
	s2_str = (unsigned char *) s2;
	while (i < n)
	{
		if ((s1_str[i] - s2_str[i]) != 0)
			return (s1_str[i] - s2_str[i]);
		i++;
	}
	return (0);
}
