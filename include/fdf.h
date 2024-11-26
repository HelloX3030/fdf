/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:48:51 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 13:28:36 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/get_next_line/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/include/ft_printf.h"
# include "MLX42/MLX42.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 2048
# define HEIGHT 2048
# define TILE_SIZE 20

// colors
# define COLOR_BLACK 0x000000FFU
# define COLOR_WHITE 0xFFFFFFFFU
# define COLOR_RED 0xFF0000FFU
# define COLOR_GREEN 0x00FF00FFU
# define COLOR_BLUE 0x0000FFFFU
# define COLOR_YELLOW 0xFFFF00FFU
# define COLOR_CYAN 0x00FFFFFFU
# define COLOR_MAGENTA 0xFF00FFFFU
# define COLOR_ORANGE 0xFFA500FFU
# define COLOR_PURPLE 0x800080FFU
# define COLOR_BROWN 0xA52A2AFFU
# define COLOR_GRAY 0x808080FFU
# define COLOR_LIGHT_GRAY 0xD3D3D3FFU
# define COLOR_DARK_GRAY 0xA9A9A9FFU

# define DEFAULT_COLOR 0
# define BACKGROUND_COLOR 0x000000FFU

// base structs
typedef struct s_point2d
{
	int				x;
	int				y;
}					t_point2d;
void				ft_set_point2d(t_point2d *point, int x, int y);
bool				ft_point_in_area(int width, int height, t_point2d *point);
void				ft_print_point2d(char *name, t_point2d *point);

typedef struct s_point3d
{
	int				x;
	int				y;
	int				z;
}					t_point3d;
void				ft_set_point3d(t_point3d *point, int x, int y, int z);
void				ft_print_point3d(char *name, t_point3d *point);

// s_projection
// o: offset
// v: viewpoint
// p: point
// t: tile size
typedef struct s_projection
{
	int				(*get_x)(t_point3d *o, t_point3d *v, t_point3d *p, int t);
	int				(*get_y)(t_point3d *o, t_point3d *v, t_point3d *p, int t);
}					t_projection;

typedef struct s_map
{
	int				width;
	int				height;
	int				**map;
	unsigned int	**color;
	t_point2d		pos;
}					t_map;

typedef struct s_fdf
{
	mlx_t			*mlx;
	int				width;
	int				height;
	t_map			map;
	mlx_image_t		*img;
	bool			update;
	t_projection	projection;
	t_point3d		offset;
	t_point3d		viewpoint;
	int				tile_size;
	float			zoom;
}					t_fdf;
void				ft_init_fdf(t_fdf *fdf, char *file_path);
void				ft_free_fdf_content(t_fdf *fdf);
void				ft_update_fdf_img(t_fdf *fdf);
void				ft_reset_fdf_view(t_fdf *fdf);

// zoom functions
# define MIN_ZOOM 0.5
# define MAX_ZOOM 3
# define ZOOM_STEP 0.07

void				ft_update_zoom_factor(t_fdf *fdf);
void				ft_zoom_in(t_fdf *fdf);
void				ft_zoom_out(t_fdf *fdf);

// util functions
int					ft_get_line_count(int fd);

// map functions
int					ft_init_map(t_map *map, char *file_path);
int					ft_init_map_size(t_map *map, char *file_path);
void				ft_print_map(t_map *map, bool print_map, bool print_color);
int					ft_parse_map(t_map *map, char *file_path);
void				ft_free_map_content(t_map *map);
void				ft_draw_fdf(t_fdf *fdf);
t_point3d			ft_get_point(t_map *map, t_point2d *point);

// base functions
void				ft_error(char *msg);
char				*ft_get_file_path(int argc, char **argv);

// graphic base functions
bool				ft_put_pixel_save(mlx_image_t *img, t_point2d *point,
						uint32_t color);
void				ft_clear_img(mlx_image_t *img, unsigned int color);

bool				ft_draw_line(mlx_image_t *img, t_point2d *start,
						t_point2d *end, uint32_t color);
void				ft_connect_tiles(t_fdf *fdf, t_point2d *start,
						t_point2d *end);

// isometric functions
int					ft_get_isometric_x(t_point3d *offset, t_point3d *viewport,
						t_point3d *point, int tile_size);
int					ft_get_isometric_y(t_point3d *offset, t_point3d *viewport,
						t_point3d *point, int tile_size);

// hooks
void				ft_hooks_setup(t_fdf *fdf);
void				ft_on_resize(int32_t width, int32_t height, void *param);
void				ft_loop(void *param);
void				ft_check_key_presses(t_fdf *fdf);

#endif
