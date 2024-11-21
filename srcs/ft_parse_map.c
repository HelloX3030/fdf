/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:51:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/21 15:21:10 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	parse_pair(int fd, t_map *map, char **pairs)
{
	char	**split;

	split = ft_split(pairs[map->pos.x], ',');
	free(pairs[map->pos.x]);
	if (!split)
	{
		close(fd);
		ft_free_map(map);
		while (pairs[++map->pos.x])
			free(pairs[map->pos.x]);
		free(pairs);
	}
	if (map->pos.x >= map->width || map->pos.y >= map->height)
	{
		ft_free_strs(split);
		return ;
	}
	map->map[map->pos.x][map->pos.y] = ft_atoi(split[0]);
	if (ft_aish(split[1]))
		map->color[map->pos.x][map->pos.y] = ft_htoi(split[1]);
	else
		map->color[map->pos.x][map->pos.y] = DEFAULT_COLOR;
	ft_free_strs(split);
}

static void	ft_parse_line(int fd, t_map *map, char *line)
{
	char	**pairs;

	pairs = ft_split(line, ' ');
	free(line);
	if (!pairs)
	{
		ft_free_map(map);
		close(fd);
		ft_error("Failed to split line");
	}
	map->pos.x = 0;
	while (pairs[map->pos.x])
	{
		parse_pair(fd, map, pairs);
		map->pos.x++;
	}
	free(pairs);
}

t_map	*ft_parse_map(char *file_name)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = ft_malloc_map(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_free_map(map);
		ft_error("Failed to open file");
	}
	line = get_next_line(fd);
	map->pos.y = 0;
	while (line)
	{
		ft_parse_line(fd, map, line);
		line = get_next_line(fd);
		map->pos.y++;
	}
	return (close(fd), map);
}
