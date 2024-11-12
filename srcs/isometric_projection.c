/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:48 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/12 13:48:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_isometric_x(int x, int y)
{
	return (x - y);
}

int	get_isometric_y(int x, int y, int z)
{
	return ((x + z) / y - y);
}
