/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:59:44 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/28 11:49:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_l(const char *s, int l)
{
	ssize_t	result;

	result = write(1, s, l);
	if (result < 0)
		return (-1);
	return (result);
}
