/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:19:08 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/07 20:37:58 by lrouchon         ###   ########.fr       */
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

int	project_x(int xyz[3], t_fdf *fdf_struct)
{
	return ((xyz[0] - xyz[1]) * cos(fdf_struct->angle) * fdf_struct->scale + fdf_struct->offset[0]);
}

int	project_y(int xyz[3], t_fdf *fdf_struct)
{
	return ((xyz[0] + xyz[1]) * sin(fdf_struct->angle) * fdf_struct->scale - xyz[2] * fdf_struct->z_scale + fdf_struct->offset[1]);
}

void	draw_line(t_fdf *fdf_struct, t_point *a, t_point *b)
{
	int	project_a[2];
	int	project_b[2];
	int	d[2];
	int	s[2];
	int	err;
	int	e2;

	project_a[0] = project_x(a->xyz, fdf_struct);
	project_a[1] = project_y(a->xyz, fdf_struct);
	project_b[0] = project_x(b->xyz, fdf_struct);
	project_b[1] = project_y(b->xyz, fdf_struct);
	d[0] = ft_abs(project_b[0]  - project_a[0]);
	if (project_a[0] < project_b[0])
		s[0] = 1;
	else
		s[0] = -1;
	d[1] = -ft_abs(project_b[1] - project_a[1]);
	if (project_a[1] < project_b[1])
		s[1] = 1;
	else
		s[1] = -1;
	err = d[0] + d[1];
	while (1)
	{
		draw_pixel(fdf_struct, project_a[0], project_a[1], a->color);
		if (project_a[0] == project_b[0] && project_a[1] == project_b[1])
			break ;
		e2 = 2 * err;
		if (e2 >= d[1])
		{
			err += d[1];
			project_a[0] += s[0];
		}
		if (e2 <= d[0])
		{
			err += d[0];
			project_a[1] += s[1];
		}
	}
}

void	draw_map(t_fdf *fdf_struct)
{
	int 	i;
	int 	j;

	i = -1;
	while (++i < fdf_struct->lines)
	{
		j = -1;
		while (++j < fdf_struct->columns - 1)
			draw_line(fdf_struct, fdf_struct->content[i][j], fdf_struct->content[i][j + 1]);
	}
	i = -1;
	while (++i < fdf_struct->lines - 1)
	{
		j = -1;
		while (++j < fdf_struct->columns)
			draw_line(fdf_struct, fdf_struct->content[i][j], fdf_struct->content[i + 1][j]);
	}
}

void	draw_image(t_fdf *fdf_struct)
{
	if (fdf_struct->img_ptr != NULL)
		mlx_destroy_image(fdf_struct->mlx_ptr, fdf_struct->img_ptr);
	fdf_struct->img_ptr = mlx_new_image(fdf_struct->mlx_ptr, MIN_WIDTH, MIN_HEIGHT);
	fdf_struct->data_addr = mlx_get_data_addr(fdf_struct->img_ptr, &fdf_struct->bpp, &fdf_struct->line_length, &fdf_struct->endian);
	draw_map(fdf_struct);
	mlx_put_image_to_window(fdf_struct->mlx_ptr, fdf_struct->win_ptr, fdf_struct->img_ptr, 0, 0);
}
