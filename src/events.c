/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:54:06 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/06 19:07:14 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_mouse(int mouse, int x, int y, void *param)
{
	t_fdf	*fdf_struct;

	(void)x;
	(void)y;
	fdf_struct = (t_fdf *)param;
	(void)fdf_struct;
	ft_printf("%d\n", mouse);
	if (mouse == 5)
	{
		fdf_struct->z_scale--;
		draw_image(fdf_struct);
	}
	if (mouse == 4)
	{
		fdf_struct->z_scale++;
		draw_image(fdf_struct);
	}
	return (0);
}

int	deal_key(int key, void *param)
{
	t_fdf	*fdf_struct;

	fdf_struct = (t_fdf *)param;
	ft_printf("%d\n", key);
	if (key == KEY_ESC)
		exit_free(fdf_struct, EXIT_SUCCESS);
	if (key == KEY_ZOOM_IN)
	{
		fdf_struct->scale++;
	}
	if (key == KEY_ZOOM_OUT)
	{
		fdf_struct->scale--;
	}
	if (key == KEY_DOWN)
		fdf_struct->offset[1] -= 10;
	if (key == KEY_UP)
		fdf_struct->offset[1] += 10;
	if (key == KEY_LEFT)
		fdf_struct->offset[0] += 10;
	if (key == KEY_RIGHT)
		fdf_struct->offset[0] -= 10;
	if (key == KEY_ONE)
		fdf_struct->angle = ISOMETRIC;
	if (key == KEY_TWO)
		fdf_struct->angle = PARALLEL;
	draw_image(fdf_struct);
	return (0);
}


