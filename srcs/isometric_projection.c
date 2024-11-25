/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:34:24 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 14:55:20 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_isometric_x(t_point3d *offset, t_point3d *viewport, t_point3d *point,
		int tile_size)
{
	(void)viewport;
	return ((sqrt(3) / 2) * (point->x - point->z) * tile_size - offset->x);
}

int	ft_get_isometric_y(t_point3d *offset, t_point3d *viewport, t_point3d *point,
		int tile_size)
{
	(void)viewport;
	return (((point->x + point->z) / 2 - point->y) * tile_size - offset->y);
}
