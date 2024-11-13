/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:51:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/13 13:29:21 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_parse_map(char *file_name)
{
	t_map	*map;
	int		x;
	int		y;

	(void)file_name;
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error();
	map->width = 5;
	map->height = 5;
	map->map = malloc(sizeof(int *) * map->height);
	if (!map->map)
		ft_error();
	y = -1;
	while (++y < map->height)
	{
		map->map[y] = malloc(sizeof(int) * map->width);
		if (!map->map[y])
			ft_error();
		x = -1;
		while (++x < map->width)
			map->map[y][x] = x % 2 + y % 2;
	}
	return (map);
}
