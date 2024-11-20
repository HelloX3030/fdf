/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:35:33 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 14:01:35 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_map *map, mlx_image_t *img, uint32_t color)
{
	// t_point	start;
	// t_point	end;
	// int		x;
	// int		y;
	// y = -1;
	// while (++y < map->height)
	// {
	// 	x = -1;
	// 	while (++x < map->width)
	// 	{
	// 		if (x < map->width - 1)
	// 		{
	// 			ft_set_point(&start, x, y, map->map[y][x]);
	// 			ft_set_point(&end, x + 1, y, map->map[y][x + 1]);
	// 			ft_connect_tiles(&start, &end, img, color);
	// 		}
	// 		if (y < map->height - 1)
	// 		{
	// 			ft_set_point(&start, x, y, map->map[y][x]);
	// 			ft_set_point(&end, x, y + 1, map->map[y + 1][x]);
	// 			ft_connect_tiles(&start, &end, img, color);
	// 		}
	// 	}
	// }
	(void)map;
	(void)img;
	(void)color;
}
