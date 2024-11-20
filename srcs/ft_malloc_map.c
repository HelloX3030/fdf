/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:09:17 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 15:39:12 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	free_map_map(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->width)
		free(map->map[x]);
	free(map->map);
	free(map);
}

static void	malloc_map(t_map *map)
{
	int	x;

	map->map = malloc(sizeof(int *) * map->width);
	if (!map->map)
	{
		free(map);
		ft_error("Failed to allocate map->map");
	}
	x = -1;
	while (++x < map->width)
	{
		map->map[x] = malloc(sizeof(int) * map->height);
		if (!map->map[x])
		{
			while (--x >= 0)
				free(map->map[x]);
			free(map->map);
			free(map);
			ft_error("Failed to allocate map->map[y]");
		}
	}
}

static void	malloc_colors(t_map *map)
{
	int	x;

	x = -1;
	map->color = malloc(sizeof(unsigned int *) * map->width);
	if (!map->color)
	{
		free_map_map(map);
		ft_error("Failed to allocate map->color");
	}
	while (++x < map->width)
	{
		map->color[x] = malloc(sizeof(unsigned int) * map->height);
		if (!map->color[x])
		{
			while (--x >= 0)
				free(map->color[x]);
			free(map->color);
			free_map_map(map);
			ft_error("Failed to allocate map->color[x]");
		}
	}
}

t_map	*ft_malloc_map(char *file_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Failed to allocate map");
	ft_init_map_size(file_name, map);
	ft_set_point2d(&map->pos, 0, 0);
	malloc_map(map);
	malloc_colors(map);
	return (map);
}
