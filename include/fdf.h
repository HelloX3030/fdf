/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:48:51 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 13:59:50 by lseeger          ###   ########.fr       */
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
# define TILE_SIZE 200

// colors
# define COLOR_BLACK 0x000000FF
# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_RED 0xFF0000FF
# define COLOR_GREEN 0x00FF00FF
# define COLOR_BLUE 0x0000FFFF
# define COLOR_YELLOW 0xFFFF00FF
# define COLOR_CYAN 0x00FFFFFF
# define COLOR_MAGENTA 0xFF00FFFF
# define COLOR_ORANGE 0xFFA500FF
# define COLOR_PURPLE 0x800080FF
# define COLOR_BROWN 0xA52A2AFF
# define COLOR_GRAY 0x808080FF
# define COLOR_LIGHT_GRAY 0xD3D3D3FF
# define COLOR_DARK_GRAY 0xA9A9A9FF

// base structs
typedef struct s_point2d
{
	int		x;
	int		y;
}			t_point2d;
void		ft_set_point2d(t_point2d *point, int x, int y);

typedef struct s_point3d
{
	int		x;
	int		y;
	int		z;
}			t_point3d;
void		ft_set_point3d(t_point3d *point, int x, int y, int z);

typedef struct s_map
{
	int		width;
	int		height;
	int		**map;
	int		**color;
}			t_map;

// util functions
int			ft_get_line_count(int fd);
bool		ft_in_charset(char c, char *set);
void		ft_free_strs(char **strs);

// map functions
void		ft_print_map(t_map *map);
t_map		*ft_malloc_map(char *file_name);

// base functions
void		ft_error(char *msg);

// graphic base functions
int			ft_get_isometric_x(int x, int y);
int			ft_get_isometric_y(int x, int y, int z);
bool		ft_put_pixel_save(mlx_image_t *img, t_point2d *point,
				uint32_t color);
void		ft_draw_line(mlx_image_t *img, t_point2d *start, t_point2d *end,
				uint32_t color);
void		ft_draw_map(t_map *map, mlx_image_t *img, uint32_t color);
mlx_image_t	*ft_update_img(mlx_t *mlx, mlx_image_t *img);

// map functions
t_map		*ft_parse_map(char *file_name);
void		ft_free_map(t_map *map);
void		ft_connect_tiles(t_point3d *start, t_point3d *end, mlx_image_t *img,
				uint32_t color);

#endif
