/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:09:17 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/19 15:56:14 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	ft_free_helper(t_map *map, int y)
{
	while (--y >= 0)
		free(map->map[y]);
	free(map->map);
	free(map);
}

static int	ft_get_map_width(int fd)
{
	char	*first_line;
	int		i;
	int		count;

	first_line = get_next_line(fd);
	count = 1;
	i = 0;
	while (first_line[i])
	{
		if (first_line[i] == ' ' && !ft_in_charset(first_line[i + 1], " \n"))
		{
			if (first_line[i + 1])
				count++;
		}
		i++;
	}
	return (free(first_line), count);
}

static void	get_size_failed(int fd, t_map *map)
{
	free(map);
	close(fd);
	ft_error("Failed to get map size");
}

static void	ft_init_map_size(char *file_name, t_map *map)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		ft_error("Failed to open file");
	}
	map->height = ft_get_line_count(fd);
	if (map->height < 0)
		get_size_failed(fd, map);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		ft_error("Failed to open file");
	}
	map->width = ft_get_map_width(fd);
	if (map->width < 0)
		get_size_failed(fd, map);
	close(fd);
}

t_map	*ft_malloc_map(char *file_name)
{
	t_map	*map;
	int		y;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Failed to allocate map");
	ft_init_map_size(file_name, map);
	map->map = malloc(sizeof(int *) * map->height);
	if (!map->map)
	{
		free(map);
		ft_error("Failed to allocate map->map");
	}
	y = -1;
	while (++y < map->height)
	{
		map->map[y] = malloc(sizeof(int) * map->width);
		if (!map->map[y])
		{
			ft_free_helper(map, y);
			ft_error("Failed to allocate map->map[y]");
		}
	}
	return (map);
}
