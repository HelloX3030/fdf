/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:02:25 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 13:57:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point3d	ft_get_point(t_fdf *fdf, t_point2d *point)
{
	t_point3d	p;

	ft_set_point3d(&p, point->x * fdf->tile_size, point->y * fdf->tile_size,
		fdf->map.map[point->x][point->y] * fdf->tile_size * fdf->y_scale);
	return (p);
}