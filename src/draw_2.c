/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:14:51 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/08 16:20:01 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	project_x(int xyz[3], t_fdf *fdf_struct)
{
	return ((xyz[0] - xyz[1]) * cos(fdf_struct->angle)
		* fdf_struct->scale + fdf_struct->offset[0]);
}

int	project_y(int xyz[3], t_fdf *fdf_struct)
{
	return ((xyz[0] + xyz[1]) * sin(fdf_struct->angle) * fdf_struct->scale
		- xyz[2] * fdf_struct->z_scale + fdf_struct->offset[1]);
}

int	get_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	line_loop(t_fdf *fdf_struct, t_line	*line, t_point *a)
{
	draw_pixel(fdf_struct, line->project_a[0], line->project_a[1], a->color);
	line->e2 = 2 * line->err;
	if (line->e2 >= line->direction[1])
	{
		line->err += line->direction[1];
		line->project_a[0] += line->slope[0];
	}
	if (line->e2 <= line->direction[0])
	{
		line->err += line->direction[0];
		line->project_a[1] += line->slope[1];
	}
}
