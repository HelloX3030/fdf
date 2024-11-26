/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_fdf_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:02 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 17:09:37 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_reset_fdf_view(t_fdf *fdf)
{
	fdf->update = true;
	fdf->projection.get_x = ft_get_isometric_x;
	fdf->projection.get_y = ft_get_isometric_y;
	fdf->tile_size = TILE_SIZE;
	fdf->offset.x = -fdf->width / 2;
	fdf->offset.y = -fdf->height / 2;
	fdf->offset.z = 0;
	ft_set_point3d_d(&fdf->viewpoint, M_PI / 2, 0, 0);
	fdf->zoom = MIN_ZOOM;
	ft_update_zoom_factor(fdf);
	fdf->y_scale = MIN_Y_SCALE;
}
