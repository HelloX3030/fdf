/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key_presses.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:01:49 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/26 16:20:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	check_camera_movement(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		fdf->offset.x -= 10;
		fdf->update = true;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		fdf->offset.x += 10;
		fdf->update = true;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		fdf->offset.y -= 10;
		fdf->update = true;
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		fdf->offset.y += 10;
		fdf->update = true;
	}
}

static void	check_projection_change(t_fdf *fdf)
{
	(void)fdf;
}

static void	check_zoom_scale_change(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		ft_zoom_out(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		ft_zoom_in(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		ft_increase_y_scale(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		ft_decrease_y_scale(fdf);
}

static void	check_viewpoint_change(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		ft_rotate_clock(fdf);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		ft_rotate_counter(fdf);
}

void	ft_check_key_presses(t_fdf *fdf)
{
	check_camera_movement(fdf);
	check_projection_change(fdf);
	check_zoom_scale_change(fdf);
	check_viewpoint_change(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		ft_reset_fdf_view(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
	{
		ft_free_fdf_content(fdf);
		mlx_terminate(fdf->mlx);
		exit(0);
	}
}
