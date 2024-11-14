/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:51:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/14 15:05:22 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_helper(t_map *map, int y)
{
	while (--y >= 0)
		free(map->map[y]);
	free(map->map);
	free(map);
}

static void	ft_get_map_width(char *first_line, t_map *map)
{
	char	*next;

	map->width = 1;
	next = ft_strchr(first_line, ' ');
	while (next)
	{
		map->width++;
		next = ft_strchr(next + 1, ' ');
	}
}

static void	ft_init_map_size(char *file_name, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		ft_error("Failed to open file");
	}
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		ft_error("Failed to read first line");
	}
	ft_get_map_width(line, map);
	map->height = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static t_map	*ft_alloc_map(char *file_name)
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

t_map	*ft_parse_map(char *file_name)
{
	t_map	*map;

	map = ft_alloc_map(file_name);
	ft_printf("map->width: %i\nmap->height: %i\n", map->width, map->height);
	return (map);
}
