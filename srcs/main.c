/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:21:44 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/28 13:26:27 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_init_fdf(&fdf, ft_get_file_path(argc, argv));
	ft_print_map(&fdf.map, true, false);
	ft_hooks_setup(&fdf);
	mlx_loop(fdf.mlx);
	ft_free_fdf_content(&fdf);
	return (0);
}

// system("leaks fdf");
