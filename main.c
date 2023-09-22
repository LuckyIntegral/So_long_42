/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:38:47 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/23 00:55:14 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "inc/sl_errors.h"

int	main(int c, char **v)
{
	t_map	*map;

	if (c != 2)
		sl_error_handler(MISSED_ARGUMENT);
	if (!sl_endwith(v[1], ".ber"))
		sl_error_handler(INVALID_MAP_EXTENSION);
	map = sl_init_map(v[1]);
	sl_validate_map(map);
	ft_printf("%s", map->map);
	return (0);
}