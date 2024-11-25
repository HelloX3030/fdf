/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:41:21 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 12:20:51 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_hooks_setup(t_fdf *fdf)
{
	mlx_resize_hook(fdf->mlx, ft_on_resize, fdf);
	mlx_loop_hook(fdf->mlx, ft_loop, fdf);
}
