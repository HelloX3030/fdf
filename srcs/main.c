/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:44 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/21 15:53:16 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	// mlx_t		*mlx;
	// mlx_image_t	*img;
	map = ft_parse_args(argc, argv);
	ft_print_map(map, false, true);
	// mlx_set_setting(MLX_MAXIMIZED, true);
	// mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	// if (!mlx)
	// 	ft_error(NULL);
	// img = ft_update_img(mlx, NULL);
	// ft_draw_map(map, img, COLOR_BLUE);
	// mlx_loop(mlx);
	// mlx_delete_image(mlx, img);
	// mlx_terminate(mlx);
	ft_free_map(map);
	system("leaks fdf");
	return (0);
}
