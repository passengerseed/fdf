/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:27:06 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/08 16:46:14 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drain_gnl_fd(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

int	count_lines(char *path)
{
	char	*line;
	int		n;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	n = 0;
	while (fd != -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		n++;
	}
	return (close(fd), n);
}

int	count_columns(char *path)
{
	char	*line;
	char	**split_line;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (drain_gnl_fd(fd), close(fd), -1);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	split_line = ft_split(line, ' ');
	if (!split_line)
		return (free(line), drain_gnl_fd(fd), close(fd), -1);
	i = 0;
	while (split_line[i])
		i++;
	free(line);
	ft_freearr(split_line);
	drain_gnl_fd(fd);
	return (close(fd), i);
}
