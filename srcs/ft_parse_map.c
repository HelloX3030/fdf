/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:51:55 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/19 16:08:29 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_helper(t_map *map, char *line, int fd)
{
	free(line);
	ft_free_map(map);
	close(fd);
}

static void	ft_parse_line(int fd, t_map *map, char *line, int y)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	if (!split)
	{
		free_helper(map, line, fd);
		ft_error("Failed to split line");
	}
	x = 0;
	ft_free_strs(split);
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
		free(line);
		line = get_next_line(fd);
		y++;
	}
	return (close(fd), map);
}
