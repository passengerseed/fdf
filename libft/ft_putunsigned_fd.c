/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:31:42 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/17 15:25:30 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int	writecount;
	int	tmp;

	writecount = 0;
	tmp = 0;
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
