/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:57:43 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/17 15:45:54 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_putnbr_base_fd(unsigned int n, int fd, const char *base)
{
	int	writecount;
	int	tmp;
	int	basecount;

	writecount = 0;
	if (ft_check_base(base))
		return (0);
	basecount = ft_strlen(base);
	if (n / basecount != 0)
	{
		tmp = ft_putnbr_base_fd(n / basecount, fd, base);
		if (tmp == -1)
			return (-1);
		writecount += tmp;
	}
	tmp = ft_putchar_fd(base[n % basecount], fd);
	if (tmp == -1)
		return (-1);
	return (writecount + tmp);
}
