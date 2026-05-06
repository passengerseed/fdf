/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:29:57 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/06 19:18:47 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_map(char *path)
{
	if (access(path, F_OK | O_RDONLY) == -1)
		return (-1);
	return (0);
}

void	exit_error(char *error_str, int status)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putendl_fd(error_str, STDERR_FILENO);
	exit(status);
}

void	exit_free(t_fdf	*fdf_struct, int status)
{
	mlx_destroy_window(fdf_struct->mlx_ptr, fdf_struct->win_ptr);
	free(fdf_struct);
	exit(status);
}

int	main(int argc, const char **argv)
{
	t_fdf			*fdf_struct;
	int				offset[2];

	if (argc <= 1)
		exit(EXIT_FAILURE);
	fdf_struct = init_fdf(argc, argv);
	offset[0] = MIN_WIDTH / 2;
	offset[1] = MIN_HEIGHT / 2;
	set_properties(fdf_struct, offset, 20, 2);
	if (check_map((char *)argv[1]) == -1)
		exit_error("invalid map file (check_map)", EXIT_FAILURE);
	fdf_struct->map_path = (char *)argv[1];
	init_map(fdf_struct->map_path, fdf_struct);
	draw_image(fdf_struct);
	// MANAGE EVENTS
	mlx_mouse_hook(fdf_struct->win_ptr, deal_mouse, (void *)fdf_struct);
	mlx_key_hook(fdf_struct->win_ptr, deal_key, (void *)fdf_struct);
	mlx_loop(fdf_struct->mlx_ptr);
	return (mlx_destroy_image(fdf_struct->mlx_ptr, fdf_struct->img_ptr), clear_map(fdf_struct), free(fdf_struct), EXIT_SUCCESS);
}
