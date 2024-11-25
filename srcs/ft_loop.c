/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:18:41 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/25 15:20:58 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_loop(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->update)
	{
		ft_printf("update screen\n");
		fdf->update = false;
		ft_clear_img(fdf->img, BACKGROUND_COLOR);
		ft_printf("cleared img\n");
		ft_draw_fdf(fdf);
	}
	ft_check_key_presses(fdf);
}
