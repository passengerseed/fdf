/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:52:59 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/07 20:37:56 by lrouchon         ###   ########.fr       */
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
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	split_line = ft_split(line, ' ');
	if (!split_line)
		return (close(fd), free(line), -1);
	i = 0;
	while (split_line[i])
		i++;
	return (close(fd), free(line), ft_freearr(split_line), i);
}

int	init_map(char *path, t_fdf *fdf_struct)
{
	int		fd;
	char	*line;
	char	**split_line;
	int		i;
	int		j;

	fdf_struct->lines = count_lines(path);
	fdf_struct->columns = count_columns(path);
	fdf_struct->content = malloc(sizeof(t_point **) * (fdf_struct->lines + 1));
	if (!fdf_struct->content)
		return (-1);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < fdf_struct->lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), clear_map(fdf_struct), -1);
		split_line = ft_split(line, ' ');
		if (!split_line)
			return (close(fd), free(line), clear_map(fdf_struct), -1);
		fdf_struct->content[i] = malloc(sizeof(t_point *) * (fdf_struct->columns + 1));
		if (!fdf_struct->content[i])
			return (close(fd), free(line), clear_map(fdf_struct), -1);
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
