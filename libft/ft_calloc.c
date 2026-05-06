/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:16:21 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:47:30 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*buf;

	buf = malloc(nmemb * n);
	if (!buf)
		return (0);
	ft_bzero(buf, n * nmemb);
	return (buf);
}
