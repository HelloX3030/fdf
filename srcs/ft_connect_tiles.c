/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_tiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:20:50 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/13 13:30:26 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_connect_tiles(t_point *start, t_point *end, mlx_image_t *img,
		uint32_t color)
{
	t_point	start_pxl;
	t_point	end_pxl;

	start_pxl.x = ft_get_isometric_x(start->x * TILE_SIZE, start->y
			* TILE_SIZE);
	start_pxl.y = ft_get_isometric_y(start->x * TILE_SIZE, start->y * TILE_SIZE,
			start->z);
	end_pxl.x = 0;
	end_pxl.y = 0;
	(void)end;
	ft_draw_line(img, &start_pxl, &end_pxl, color);
}
