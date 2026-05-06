/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:08:01 by lrouchon          #+#    #+#             */
/*   Updated: 2026/03/18 16:03:05 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	max_len;
	char	*newstr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		newstr = malloc(1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	max_len = s_len - start;
	if (len > max_len)
		len = max_len;
	newstr = malloc((sizeof(char) * (len + 1)));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s + start, len + 1);
	return (newstr);
}
