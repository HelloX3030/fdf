/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:34:24 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 17:06:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_isometric_x(t_point3d *offset, t_point3d_d *viewport,
		t_point3d *point)
{
	double	cos_y;
	double	sin_y;
	double	rotated_x;
	double	rotated_z;
	double	cos_x;
	double	sin_x;
	double	rotated_y;
	double	cos_z;
	double	sin_z;
	double	final_x;
	double	final_y;
	double	final_z;

	// Precompute sine and cosine values for each axis
	cos_y = cos(viewport->y);
	sin_y = sin(viewport->y);
	cos_x = cos(viewport->x);
	sin_x = sin(viewport->x);
	cos_z = cos(viewport->z);
	sin_z = sin(viewport->z);
	// Y-axis rotation
	rotated_x = cos_y * point->x - sin_y * point->z;
	rotated_z = sin_y * point->x + cos_y * point->z;
	// X-axis rotation
	rotated_y = cos_x * point->y - sin_x * rotated_z;
	rotated_z = sin_x * point->y + cos_x * rotated_z;
	// Z-axis rotation
	final_x = cos_z * rotated_x - sin_z * rotated_y;
	final_y = sin_z * rotated_x + cos_z * rotated_y;
	final_z = rotated_z;
	// Return value (you may need to adjust this for your needs)
	return ((sqrt(3) / 2) * (final_x - final_z) - offset->x);
}

int	ft_get_isometric_y(t_point3d *offset, t_point3d_d *viewport,
		t_point3d *point)
{
	double	cos_y;
	double	sin_y;
	double	rotated_x;
	double	rotated_z;
	double	cos_x;
	double	sin_x;
	double	rotated_y;
	double	cos_z;
	double	sin_z;
	double	final_x;
	double	final_y;
	double	final_z;

	// Precompute sine and cosine values for each axis
	cos_y = cos(viewport->y);
	sin_y = sin(viewport->y);
	cos_x = cos(viewport->x);
	sin_x = sin(viewport->x);
	cos_z = cos(viewport->z);
	sin_z = sin(viewport->z);
	// Y-axis rotation
	rotated_x = cos_y * point->x - sin_y * point->z;
	rotated_z = sin_y * point->x + cos_y * point->z;
	// X-axis rotation
	rotated_y = cos_x * point->y - sin_x * rotated_z;
	rotated_z = sin_x * point->y + cos_x * rotated_z;
	// Z-axis rotation
	final_x = cos_z * rotated_x - sin_z * rotated_y;
	final_y = sin_z * rotated_x + cos_z * rotated_y;
	final_z = rotated_z;
	// Calculate and return the isometric Y coordinate
	return (((final_x + final_z) / 2 - final_y) - offset->y);
}
