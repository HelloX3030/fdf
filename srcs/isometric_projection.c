/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:34:24 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/27 14:18:32 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_isometric(t_point3d *point, t_point2d *pixel_pos)
{
	pixel_pos->x = (point->x - point->y) * cos(M_PI / 6);
	pixel_pos->y = (point->x + point->y) * sin(M_PI / 6) - point->z;
}
