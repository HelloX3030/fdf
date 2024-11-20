/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:11:13 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/20 16:01:44 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

static void	get_size_failed(t_map *map)
{
	free(map);
	ft_error("get size failed");
}

void	ft_init_map_size(char *file_name, t_map *map)
{
	int		fd;
	char	*buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		ft_error("Failed to open file");
	}
	map->height = ft_get_line_count(fd);
	close(fd);
	if (map->height < 0)
		get_size_failed(map);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		ft_error("Failed to open file");
	}
	map->width = ft_get_map_width(fd);
	buffer = get_buffer(fd);
	buffer[0] = 0;
	close(fd);
	if (map->width < 0)
		get_size_failed(map);
}
