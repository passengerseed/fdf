/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:52:59 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/06 17:25:59 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_lines(char *path)
{
	char	*line;
	int		n;
	int		fd;

	fd = open(path, O_RDONLY);
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
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	i = 0;
	while (split_line[i])
		i++;
	return (close(fd), ft_freearr(split_line), free(line), i);
}

void	init_map(char *path, t_fdf *fdf_struct)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		i;
	int		j;

	fdf_struct->lines = count_lines(path);
	fdf_struct->columns = count_columns(path);
	fdf_struct->content = malloc(sizeof(t_point **) * (fdf_struct->lines + 1));
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < fdf_struct->lines)
	{
		line = get_next_line(fd);
		split_line = ft_split(line, ' ');
		fdf_struct->content[i] = malloc(sizeof(t_point *) * (fdf_struct->columns + 1));
		j = 0;
		while (j < fdf_struct->columns)
		{
			fdf_struct->content[i][j] = init_point(j, i, split_line[j], fdf_struct);
			j++;
		}
		fdf_struct->content[i][j] = NULL;
		ft_freearr(split_line);
		free(line);
		i++;
	}
	fdf_struct->content[i] = NULL;
	close(fd);
}

void	clear_map(t_fdf *fdf_struct)
{
	int	i;
	int	j;

	i = -1;
	while (fdf_struct->content[++i])
	{
		j = -1;
		while (fdf_struct->content[i][++j])
			free(fdf_struct->content[i][j]);
		free(fdf_struct->content[i]);
	}
	free(fdf_struct->content);
	free(fdf_struct);
}