/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:17:28 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/19 14:07:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_map *map)
{
	int	x;
	int	y;

	ft_printf("print_map\n");
	ft_printf("width: %d\n", map->width);
	ft_printf("height: %d\n", map->height);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			ft_printf("%d ", map->map[y][x]);
		ft_printf("\n");
	}
}
