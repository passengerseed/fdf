/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:43:19 by lrouchon          #+#    #+#             */
/*   Updated: 2026/02/15 16:43:22 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(const char c, const char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	treat_args(va_list args, char c)
{
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if ((c == 'd' || c == 'i'))
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunsigned_fd(va_arg(args, unsigned int), 1));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 'x')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 1,
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), 1,
				"0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putmem_fd(va_arg(args, unsigned long), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		writecount;
	int		tmp;
	size_t	i;
	va_list	args;

	writecount = 0;
	i = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && is_charset(str[i + 1], "cspdiuxX%"))
		{
			tmp = treat_args(args, str[i + 1]);
			i++;
		}
		else
			tmp = ft_putchar_fd(str[i], 1);
		if (tmp == -1)
			return (-1);
		writecount += tmp;
		i++;
	}
	return (writecount);
}
