/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:38:47 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/21 23:17:38 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "inc/sl_errors.h"

int	main(int c, char **v)
{
	t_map	*map;
	int		status;

	if (c != 2 || !sl_endwith(v[1], ".ber"))
		sl_error_handler(INVALID_MAP_EXTENSION);
	map = sl_init_map(v[1]);
	// ft_printf("{%s}", map->map);
	sl_validate_map(map);
	status = 0;
	return (status);
}
