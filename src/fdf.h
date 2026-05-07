/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrouchon <lrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:29:53 by lrouchon          #+#    #+#             */
/*   Updated: 2026/05/07 19:40:36 by lrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <errno.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

/* MINIMUM WINDOW SIZE */
# define MIN_WIDTH 1920
# define MIN_HEIGHT 1080
# define SCALE 40
# define Z_SCALE 5

/* KEYS */
# define KEY_ESC 65307
# define KEY_ZOOM_IN 65451
# define KEY_ZOOM_OUT 65453
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_SPACE 32
# define KEY_ONE 65436
# define KEY_TWO 65433

/* COLORS */
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define ISOMETRIC 0.523599
# define PARALLEL 0.0

typedef	struct s_point
{
	int				xyz[3];
	unsigned int	color;
}	t_point;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*data_addr;
	void	*img_ptr;
	int		bpp;
	int		line_length;
	int		endian;
	double	angle;
	int		offset[2];
	int		scale;
	int		z_scale;
	int		lines;
	int		columns;
	t_point	***content;
	char	*map_path;
}	t_fdf;

void			error(char *error_str);
t_fdf			*init_fdf(int argc, const char **argv);
int				deal_mouse(int mouse, int x, int y, void *param);
int				deal_key(int key, void *param);
void			exit_free(t_fdf	*fdf_struct);
int				count_lines(char *path);
int				count_columns(char *path);
int				init_map(char *path, t_fdf *fdf_struct);
void			set_properties(t_fdf *fdf_struct, int scale, int z_scale);
void			clear_map(t_fdf *fdf_struct);
t_point			*init_point(int x, int y, char *z, t_fdf *fdf_struct);
void			draw_pixel(t_fdf *fdf_struct, int x, int y, unsigned int color);
void			draw_line(t_fdf *fdf_struct, t_point *a, t_point *b);
void			draw_map(t_fdf *fdf_struct);
void			draw_image(t_fdf *fdf_struct);
int				project_x(int xyz[3], t_fdf *fdf_struct);
int				project_y(int xyz[3], t_fdf *fdf_struct);

#endif /* FDF_H */
