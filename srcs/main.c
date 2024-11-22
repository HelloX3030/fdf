/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:44 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/22 15:38:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_init_fdf(&fdf, ft_get_file_path(argc, argv));
	ft_print_map(&fdf.map, false, false);
	ft_hooks_setup(&fdf);
	// ft_draw_map(map, img, COLOR_BLUE);
	mlx_loop(fdf.mlx);
	ft_free_fdf_content(&fdf);
	return (0);
}

// system("leaks fdf");
