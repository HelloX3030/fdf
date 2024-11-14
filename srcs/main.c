/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:44 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/14 15:06:45 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;

	map = ft_parse_map("maps/42.fdf");
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!mlx)
		ft_error(NULL);
	img = ft_update_img(mlx, NULL);
	ft_draw_map(map, img, COLOR_BLUE);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	ft_free_map(map);
	mlx_terminate(mlx);
	return (0);
}
