/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:54:48 by lseeger           #+#    #+#             */
/*   Updated: 2024/10/28 12:37:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	test;
	int	len1;
	int	len2;

	test = -1;
	len1 = printf("%i\n", test);
	printf("printf:\n");
	len2 = ft_printf("%i\n", test);
	printf("ft_printf\n");
	printf("expected: %i\ngot: %i\n", len1, len2);
	return (0);
}
