/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:29:04 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 13:47:47 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_points(t_point2d *start, t_point2d *end, t_point2d *dif,
		t_point2d *step)
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

static void	ft_draw(mlx_image_t *img, t_point2d *start, t_point2d *end,
		uint32_t color)
{
	t_point2d	dif;
	t_point2d	step;
	int			err;
	int			e2;

	init_points(start, end, &dif, &step);
	err = dif.x - dif.y;
	while (1)
	{
		ft_put_pixel_save(img, start, color);
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

void	ft_draw_line(mlx_image_t *img, t_point2d *start, t_point2d *end,
		uint32_t color)
{
	if (!ft_point_in_area(img->width, img->height, start)
		|| !ft_point_in_area(img->width, img->height, end))
		return ;
	ft_draw(img, start, end, color);
}
