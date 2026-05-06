/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:12:28 by lrouchon          #+#    #+#             */
/*   Updated: 2025/11/15 15:45:40 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	char	*c_s;

	i = 0;
	c_s = (char *)s;
	while (c_s[i])
	{
		f(i, &c_s[i]);
		i++;
	}
	c_s[i] = '\0';
}
