/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:38:47 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/21 17:42:39 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int c, char **v)
{
	t_map	map;
	int		status;

	if (c != 2 || !sl_endwith(".ber"))
		sl_error_handler(INVALID_MAP_EXTENSION);
	map = init_map(v[1]);
	sl_validate_map(map);
	status = 1;
	return (status);
}
