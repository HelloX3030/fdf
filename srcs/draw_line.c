/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:29:04 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/14 13:17:40 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_points(t_point *start, t_point *end, t_point *dif,
		t_point *step)
{
	dif->x = abs(end->x - start->x);
	dif->y = abs(end->y - start->y);
	if (start->x < end->x)
		step->x = 1;
	else
		step->x = -1;
	if (start->y < end->y)
		step->y = 1;
	else
		step->y = -1;
}

void	ft_draw_line(mlx_image_t *img, t_point *start, t_point *end,
		uint32_t color)
{
	t_point	dif;
	t_point	step;
	int		err;
	int		e2;

	init_points(start, end, &dif, &step);
	err = dif.x - dif.y;
	while (1)
	{
		if (start->x >= 0 && (uint32_t)start->x < img->width && start->y >= 0
			&& (uint32_t)start->y < img->height)
			mlx_put_pixel(img, start->x, start->y, color);
		if (start->x == end->x && start->y == end->y)
			break ;
		e2 = 2 * err;
		if (e2 > -dif.y)
		{
			err -= dif.y;
			start->x += step.x;
		}
		if (e2 < dif.x)
		{
			err += dif.x;
			start->y += step.y;
		}
	}
}
