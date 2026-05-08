/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:11:09 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/08 15:52:53 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(int argc, const char **argv)
{
	t_fdf	*new_fdf;

	(void)argc;
	(void)argv;
	new_fdf = malloc(sizeof(t_fdf));
	if (!new_fdf)
		return (NULL);
	new_fdf->img_ptr = NULL;
	new_fdf->content = NULL;
	new_fdf->mlx_ptr = mlx_init();
	if (!new_fdf->mlx_ptr)
		return (free(new_fdf), NULL);
	new_fdf->win_ptr = mlx_new_window(new_fdf->mlx_ptr,
			MIN_WIDTH, MIN_HEIGHT, "fdf");
	if (!new_fdf->win_ptr)
		return (free(new_fdf->mlx_ptr), free(new_fdf), NULL);
	return (new_fdf);
}

void	set_properties(t_fdf *fdf_struct, int scale, int z_scale)
{
	fdf_struct->offset[0] = MIN_WIDTH / 2;
	fdf_struct->offset[1] = MIN_HEIGHT / 2;
	fdf_struct->scale = scale;
	fdf_struct->z_scale = z_scale;
	fdf_struct->angle = ISOMETRIC;
}

t_point	*init_point(int x, int y, char *z, t_fdf *fdf_struct)
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
		ft_freearr(split_point);
	}
	else
	{
		new_point->color = WHITE;
		z_tmp = ft_atoi(z);
	}
	new_point->xyz[0] = x;
	new_point->xyz[1] = y;
	new_point->xyz[2] = z_tmp;
	return (new_point);
}
