/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:35:33 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/13 13:01:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_map(t_map *map, mlx_image_t *img, uint32_t color)
{
	t_point	start;
	t_point	end;
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (x > 0)
			{
				ft_set_point(&start, x - 1, y, 0);
				ft_set_point(&end, x, y, 0);
				ft_draw_line(img, &start, &end, color);
			}
		}
	}
}
