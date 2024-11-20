/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:51:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 14:02:22 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	parse_pair(int fd, t_map *map, char **pairs, t_point2d *pos)
{
	char	**split;

	split = ft_split(pairs[pos->x], ',');
	free(pairs[pos->x]);
	if (!split)
	{
		close(fd);
		ft_free_map(map);
		while (pairs[++pos->x])
			free(pairs[pos->x]);
		free(pairs);
	}
	map->map[pos->x][pos->y] = ft_atoi(split[0]);
	if (split[1])
		map->color[pos->x][pos->y] = ft_htoi(split[1]);
}

static void	ft_parse_line(int fd, t_map *map, char *line, int y)
{
	char		**pairs;
	int			x;
	t_point2d	pos;

	pairs = ft_split(line, ' ');
	free(line);
	if (!pairs)
	{
		ft_free_map(map);
		close(fd);
		ft_error("Failed to split line");
	}
	x = 0;
	while (pairs[x])
	{
		ft_set_point2d(&pos, x, y);
		parse_pair(fd, map, pairs, &pos);
		x++;
	}
	free(pairs);
}

t_map	*ft_parse_map(char *file_name)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		y;

	map = ft_malloc_map(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_free_map(map);
		ft_error("Failed to open file");
	}
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		ft_parse_line(fd, map, line, y);
		line = get_next_line(fd);
		y++;
	}
	return (close(fd), map);
}
