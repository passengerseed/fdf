/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:57:00 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:47:49 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int n)
{
	size_t	n_size;

	n_size = 1;
	if (n < 0)
	{
		n *= -1;
		n_size++;
	}
	while (n >= 10)
	{
		n /= 10;
		n_size++;
	}
	return (n_size);
}

char	*ft_itoa(int n)
{
	size_t	newstr_size;
	char	*newstr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	newstr_size = ft_count(n);
	newstr = malloc(sizeof(char) * (newstr_size + 1));
	if (!newstr)
		return (0);
	newstr[newstr_size] = '\0';
	newstr_size--;
	if (n < 0)
	{
		n *= -1;
		newstr[0] = '-';
	}
	while (n > 0)
	{
		newstr[newstr_size] = (n % 10) + '0';
		n /= 10;
		newstr_size--;
	}
	return (newstr);
}
