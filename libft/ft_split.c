/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:10:56 by lrouchon          #+#    #+#             */
/*   Updated: 2026/03/18 16:04:06 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			w++;
		i++;
	}
	return (w);
}

static int	ft_splitcpy(char **arr, char const *s, char c)
{
	size_t	i_newarr;
	size_t	i;
	size_t	j;

	i_newarr = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			arr[i_newarr] = ft_substr(s, i, j);
			if (!arr[i_newarr])
				return (-1);
			i_newarr++;
		}
		i++;
	}
	arr[i_newarr] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**newarr;

	newarr = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!newarr)
		return (NULL);
	if (ft_splitcpy(newarr, s, c) == -1)
		return (ft_freearr(newarr), NULL);
	return (newarr);
}
