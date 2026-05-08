/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:19:08 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/08 16:19:46 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_fdf *fdf_struct, int x, int y, unsigned int color)
{
	size_t	offset;

	if (x < 0 || y < 0 || x >= MIN_WIDTH || y >= MIN_HEIGHT)
		return ;
	offset = y * (fdf_struct->line_length / (fdf_struct->bpp / 8));
	offset += x;
	((unsigned int *)fdf_struct->data_addr)[offset] = color;
}

void	draw_line(t_fdf *fdf_struct, t_point *a, t_point *b)
{
	t_line	*line;

	line = ft_calloc(sizeof(t_line), 1);
	if (!line)
		return ;
	line->project_a[0] = project_x(a->xyz, fdf_struct);
	line->project_a[1] = project_y(a->xyz, fdf_struct);
	line->project_b[0] = project_x(b->xyz, fdf_struct);
	line->project_b[1] = project_y(b->xyz, fdf_struct);
	line->direction[0] = ft_abs(line->project_b[0] - line->project_a[0]);
	line->slope[0] = get_slope(line->project_a[0], line->project_b[0]);
	line->direction[1] = -ft_abs(line->project_b[1] - line->project_a[1]);
	line->slope[1] = get_slope(line->project_a[1], line->project_b[1]);
	line->err = line->direction[0] + line->direction[1];
	while (line->project_a[0] != line->project_b[0]
		&& line->project_a[1] != line->project_b[1])
		line_loop(fdf_struct, line, a);
	free(line);
}

void	draw_map(t_fdf *fdf_struct)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf_struct->lines)
	{
		j = -1;
		while (++j < fdf_struct->columns - 1)
			draw_line(fdf_struct, fdf_struct->content[i][j],
				fdf_struct->content[i][j + 1]);
	}
	i = -1;
	while (++i < fdf_struct->lines - 1)
	{
		j = -1;
		while (++j < fdf_struct->columns)
			draw_line(fdf_struct, fdf_struct->content[i][j],
				fdf_struct->content[i + 1][j]);
	}
}

void	draw_image(t_fdf *fdf_struct)
{
	if (fdf_struct->img_ptr != NULL)
		mlx_destroy_image(fdf_struct->mlx_ptr, fdf_struct->img_ptr);
	fdf_struct->img_ptr = mlx_new_image(fdf_struct->mlx_ptr,
			MIN_WIDTH, MIN_HEIGHT);
	fdf_struct->data_addr = mlx_get_data_addr(fdf_struct->img_ptr,
			&fdf_struct->bpp, &fdf_struct->line_length,
			&fdf_struct->endian);
	draw_map(fdf_struct);
	mlx_put_image_to_window(fdf_struct->mlx_ptr,
		fdf_struct->win_ptr, fdf_struct->img_ptr, 0, 0);
}
