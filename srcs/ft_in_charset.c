/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_charset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:43 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/19 15:43:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

bool	ft_in_charset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}
