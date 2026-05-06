/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:09:44 by lrouchon          #+#    #+#             */
/*   Updated: 2025/12/11 17:49:47 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*newstr;

	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (ft_ischarset(set, s1[i]))
		i++;
	while (ft_ischarset(set, s1[j - 1]))
		j--;
	if (i >= j)
		return (ft_strdup(""));
	newstr = malloc((sizeof(char) * ((j - i) + 1)));
	if (!newstr)
		return (0);
	while (i != j)
		newstr[k++] = s1[i++];
	newstr[k] = '\0';
	return (newstr);
}
