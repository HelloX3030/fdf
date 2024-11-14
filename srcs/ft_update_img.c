/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:41:10 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/14 15:05:46 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*ft_update_img(mlx_t *mlx, mlx_image_t *img)
{
	if (!img)
	{
		img = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_error("Failed to update image");
		return (img);
	}
	return (img);
}
