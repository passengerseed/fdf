/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:27:06 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/08 19:20:10 by lrouchon         ###   ########.fr       */
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

int	count_columns(char *line)
{
	char	**split_line;
	int		i;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (-1);
	i = 0;
	while (split_line[i])
		i++;
	ft_freearr(split_line);
	return (i);
}

static int	count_lines_loop(int fd, t_fdf *fdf_struct)
{
	int		n_columns;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	n_columns = count_columns(line);
	if (fdf_struct->columns == 0 || n_columns == fdf_struct->columns)
		fdf_struct->columns = n_columns;
	else
	{
		fdf_struct->columns = 0;
		free(line);
		drain_gnl_fd(fd);
		return (-1);
	}
	free(line);
	return (0);
}

void	count_lines(char *path, t_fdf *fdf_struct)
{
	int		n_lines;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	n_lines = 0;
	while (count_lines_loop(fd, fdf_struct) != -1)
		n_lines++;
	fdf_struct->lines = n_lines;
	close(fd);
}
