/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:13:11 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/19 15:06:22 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*find_next_nl(char *buffer, ssize_t bytes_read)
{
	ssize_t	i;

	i = 0;
	while (i < bytes_read && buffer[i])
	{
		if (buffer[i] == '\n')
			return (buffer + i);
		i++;
	}
	return (NULL);
}

static int	count_nls(char *buffer, ssize_t bytes_read)
{
	char	*old_nl;
	char	*next_nl;
	int		count;

	count = 0;
	old_nl = buffer;
	next_nl = find_next_nl(buffer, bytes_read);
	while (next_nl)
	{
		if (next_nl - old_nl > 1)
			count++;
		old_nl = next_nl;
		next_nl++;
		next_nl = find_next_nl(next_nl, bytes_read - (next_nl - buffer));
	}
	return (count);
}

int	ft_get_line_count(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		count;
	ssize_t	bytes_read;

	count = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		count += count_nls(buffer, bytes_read);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (-1);
	return (count);
}
