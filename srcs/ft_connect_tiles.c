/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_tiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:20:50 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 14:01:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_connect_tiles(t_point3d *start, t_point3d *end, mlx_image_t *img,
		uint32_t color)
{
	// t_point	start_pxl;
	// t_point	end_pxl;
	// start_pxl.x = ft_get_isometric_x(start->x * TILE_SIZE + 900, start->z
	// 		+ 700);
	// start_pxl.y = ft_get_isometric_y(start->x * TILE_SIZE + 900, start->y
	// 		* TILE_SIZE - 200, start->z + 700);
	// end_pxl.x = ft_get_isometric_x(end->x * TILE_SIZE + 900, end->z + 700);
	// end_pxl.y = ft_get_isometric_y(end->x * TILE_SIZE + 900, end->y
	// * TILE_SIZE
	// 		- 200, end->z + 700);
	// ft_printf("connect tiles\n start: (%i, %i, %i)\n end: (%i, %i, %i)\n",
	// 	start->x, start->y, start->z, end->x, end->y, end->z);
	// ft_printf(" start_pxl: (%i, %i)\n end_pxl: (%i, %i)\n", start_pxl.x,
	// 	start_pxl.y, end_pxl.x, end_pxl.y);
	// ft_draw_line(img, &start_pxl, &end_pxl, color);
	(void)start;
	(void)end;
	(void)img;
	(void)color;
}
