/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:28:21 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/21 12:33:55 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*ft_parse_args(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Invalid amount of arguments, Usage: ./fdf <map_path>");
	ft_printf("Parsing map: %s\n", argv[1]);
	return (ft_parse_map(argv[1]));
}
