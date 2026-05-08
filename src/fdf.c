/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:29:57 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/08 15:51:30 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_map(char *path)
{
	if (access(path, F_OK | O_RDONLY) == -1)
		return (-1);
	return (0);
}

void	error(char *error_str)
{
	ft_putstr_fd("ERROR: ", STDERR_FILENO);
	ft_putendl_fd(error_str, STDERR_FILENO);
}

void	exit_free(t_fdf	*fdf_struct)
{
	if (fdf_struct->img_ptr)
		mlx_destroy_image(fdf_struct->mlx_ptr, fdf_struct->img_ptr);
	if (fdf_struct->win_ptr)
		mlx_destroy_window(fdf_struct->mlx_ptr, fdf_struct->win_ptr);
	if (fdf_struct->mlx_ptr)
	{
		mlx_destroy_display(fdf_struct->mlx_ptr);
		free(fdf_struct->mlx_ptr);
	}
	clear_map(fdf_struct);
	free(fdf_struct);
	exit(EXIT_SUCCESS);
}

int	main(int argc, const char **argv)
{
	t_fdf			*fdf_struct;

	if (argc <= 1)
		return (error("not enough arguments"), EXIT_FAILURE);
	if (check_map((char *)argv[1]) == -1)
		return (error("invalid map file"), EXIT_FAILURE);
	fdf_struct = init_fdf(argc, argv);
	if (!fdf_struct)
		return (error("couldn't initialize mlx"), EXIT_FAILURE);
	set_properties(fdf_struct, 20, 2);
	fdf_struct->map_path = (char *)argv[1];
	if (init_map(fdf_struct->map_path, fdf_struct) == -1)
		return (exit_free(fdf_struct),
			error("couldn't initialize mlx"), EXIT_FAILURE);
	draw_image(fdf_struct);
	mlx_mouse_hook(fdf_struct->win_ptr, deal_mouse, (void *)fdf_struct);
	mlx_key_hook(fdf_struct->win_ptr, deal_key, (void *)fdf_struct);
	mlx_loop(fdf_struct->mlx_ptr);
	return (exit_free(fdf_struct), EXIT_SUCCESS);
}
