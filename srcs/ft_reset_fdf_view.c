/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_fdf_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:53:02 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 14:52:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_reset_fdf_view(t_fdf *fdf)
{
	fdf->update = true;
	fdf->projection.get_x = ft_get_isometric_x;
	fdf->projection.get_y = ft_get_isometric_y;
	fdf->tile_size = TILE_SIZE;
	fdf->offset.x = (fdf->map.width * fdf->tile_size) / 2;
	fdf->offset.y = (fdf->map.height * fdf->tile_size) / 2;
	fdf->offset.z = 0;
	ft_set_point3d(&fdf->viewpoint, 0, 0, 0);
}
