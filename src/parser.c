/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:52:59 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/08 16:46:47 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_loop(int fd, int i, t_fdf *fdf_struct)
{
	char	*line;
	char	**split_line;
	int		j;

	line = get_next_line(fd);
	if (!line)
		return (drain_gnl_fd(fd), close(fd), clear_map(fdf_struct), -1);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	split_line = ft_split(line, ' ');
	if (!split_line)
		return (free(line), drain_gnl_fd(fd),
			close(fd), clear_map(fdf_struct), -1);
	fdf_struct->content[i] = ft_calloc(sizeof(t_point *),
			fdf_struct->columns + 1);
	if (!fdf_struct->content[i])
		return (free(line), ft_freearr(split_line),
			drain_gnl_fd(fd), close(fd), clear_map(fdf_struct), -1);
	j = -1;
	while (++j < fdf_struct->columns)
	{
		fdf_struct->content[i][j] = init_point(j, i, split_line[j], fdf_struct);
		if (!fdf_struct->content[i][j])
			return (free(line), ft_freearr(split_line),
				drain_gnl_fd(fd), close(fd), clear_map(fdf_struct), -1);
	}
	return (ft_freearr(split_line), free(line), 0);
}

int	init_map(char *path, t_fdf *fdf_struct)
{
	int		fd;
	int		i;

	fdf_struct->lines = count_lines(path);
	fdf_struct->columns = count_columns(path);
	if (fdf_struct->lines == -1 || fdf_struct->columns == -1)
		return (-1);
	fdf_struct->content = ft_calloc(sizeof(t_point **), fdf_struct->lines + 1);
	if (!fdf_struct->content)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (clear_map(fdf_struct), -1);
	i = 0;
	while (i < fdf_struct->lines)
	{
		if (map_loop(fd, i, fdf_struct) == -1)
		{
			if (fd != -1)
				close(fd);
			return (-1);
		}
		i++;
	}
	fdf_struct->content[i] = NULL;
	return (close(fd), 0);
}

void	clear_map(t_fdf *fdf_struct)
{
	int	i;
	int	j;

	if (!fdf_struct->content)
		return ;
	i = -1;
	while (fdf_struct->content[++i])
	{
		j = -1;
		while (fdf_struct->content[i][++j])
			free(fdf_struct->content[i][j]);
		free(fdf_struct->content[i]);
	}
	free(fdf_struct->content);
	fdf_struct->content = NULL;
}
