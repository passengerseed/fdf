/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:01:24 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/07 20:21:47 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif /* BUFFER_SIZE */

static char	*join_free(char *s1, char *s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	if (!new_str)
		return (free(s1), NULL);
	free(s1);
	return (new_str);
}

static char	*extract_rem(char *buf)
{
	char	*str_rem;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	str_rem = ft_calloc(sizeof(char), ft_strlen(buf) - i + 1);
	if (!str_rem)
		return (free(buf), NULL);
	i++;
	while (buf[i])
		str_rem[j++] = buf[i++];
	free(buf);
	return (str_rem);
}

static char	*fetch_line(char *buf)
{
	char	*new_line;
	size_t	i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	new_line = ft_calloc(sizeof(char), i + 2);
	if (!new_line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		new_line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		new_line[i++] = '\n';
	return (new_line);
}

static char	*fill_buf(int fd, char *rem)
{
	char	*buf;
	ssize_t	n_read;

	if (!rem)
	{
		rem = ft_calloc(1, 1);
		if (!rem)
			return (NULL);
	}
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (free(rem), NULL);
	n_read = 1;
	while (!ft_strchr(buf, '\n') && n_read > 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read < 0)
			return (free(buf), free(rem), NULL);
		buf[n_read] = '\0';
		rem = join_free(rem, buf);
		if (!rem)
			return (free(buf), NULL);
	}
	return (free(buf), rem);
}

char	*get_next_line(int fd)
{
	static char		*buf[1024];
	char			*new_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = fill_buf(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	new_str = fetch_line(buf[fd]);
	buf[fd] = extract_rem(buf[fd]);
	if (!new_str)
		free(buf[fd]);
	return (new_str);
}
