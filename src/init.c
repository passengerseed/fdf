/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:11:09 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/06 19:03:50 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(int argc, const char **argv)
{
	t_fdf	*new_fdf;

	(void)argc;
	(void)argv;
	new_fdf = malloc(sizeof(t_fdf));
	new_fdf->mlx_ptr = mlx_init();
	if (!new_fdf->mlx_ptr)
	{
		free(new_fdf);
		exit_error("couldn't initialize mlx_ptr (init_fdf).", EXIT_FAILURE);
	}
	new_fdf->win_ptr = mlx_new_window(new_fdf->mlx_ptr, MIN_WIDTH, MIN_HEIGHT, "fdf");
	if (!new_fdf->win_ptr)
	{
		free(new_fdf);
		exit_error("couldn't initialize win_ptr (init_fdf).", EXIT_FAILURE);
	}
	return (new_fdf);
}

void	set_properties(t_fdf *fdf_struct, int offset[2], int scale, int z_scale)
{
	fdf_struct->offset[0] = offset[0];
	fdf_struct->offset[1] = offset[1];
	fdf_struct->scale = scale;
	fdf_struct->z_scale = z_scale;
	fdf_struct->angle = ISOMETRIC;
}

t_point		*init_point(int x, int y, char *z, t_fdf *fdf_struct)
{
	t_point	*new_point;
	int		z_tmp;
	char	**split_point;

	(void)fdf_struct;
	new_point = malloc(sizeof(t_point));
	if (!new_point)
		return (NULL);
	if (ft_strchr(z, ',') != NULL)
	{
		split_point = ft_split(z, ',');
		z_tmp = ft_atoi(split_point[0]);
		new_point->color = *(int *)split_point[1];
	}
	else
	{
		new_point->color = WHITE;
		z_tmp = ft_atoi(z);
	}
	// new_point->xyz[0] = (x - y) * cos(ISOMETRIC) * fdf_struct->scale + fdf_struct->offset[0];
	// new_point->xyz[1] = (x + y) * sin(ISOMETRIC) * fdf_struct->scale - z_tmp * fdf_struct->z_scale + fdf_struct->offset[1];
	new_point->xyz[0] = x;
	new_point->xyz[1] = y;
	new_point->xyz[2] = z_tmp;
	return (new_point);
}
