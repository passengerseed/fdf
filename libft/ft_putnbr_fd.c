/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:15:16 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/17 15:46:35 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	writecount;
	int	tmp;

	writecount = 0;
	if (n == -2147483648)
	{
		return (ft_putstr_fd("-2147483648", fd));
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		writecount += 1;
		n *= -1;
	}
	if (n > 9)
	{
		tmp = ft_putnbr_fd(n / 10, fd);
		if (tmp == -1)
			return (-1);
		writecount += tmp;
	}
	tmp = ft_putchar_fd((n % 10) + '0', fd);
	if (tmp == -1)
		return (-1);
	return (writecount + tmp);
}
