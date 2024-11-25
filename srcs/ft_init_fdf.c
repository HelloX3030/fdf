/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:54:27 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 14:54:09 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_init_fdf(t_fdf *fdf, char *file_path)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!fdf->mlx)
		ft_error(NULL);
	fdf->width = WIDTH;
	fdf->height = HEIGHT;
	if (ft_init_map(&fdf->map, file_path) < 0)
	{
		mlx_terminate(fdf->mlx);
		ft_error("Failed to allocate map!");
	}
	if (ft_parse_map(&fdf->map, file_path) < 0)
	{
		ft_free_map_content(&fdf->map);
		mlx_terminate(fdf->mlx);
		ft_error("Failed to parse map!");
	}
	fdf->img = NULL;
	ft_update_fdf_img(fdf);
	ft_reset_fdf_view(fdf);
}
