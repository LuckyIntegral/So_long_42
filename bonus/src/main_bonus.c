/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:11:42 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/30 23:07:32 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
#include "../inc/sl_errors_bonus.h"

static int	sl_mlx_map(t_map *map)
{
	t_data	data;

	data.map = map;
	sl_init_mlx_struct(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		(free(map), sl_error_handler(MALLOC_FAIL));
	data.mlx_window = mlx_new_window(data.mlx_ptr,
			map->width * IMAGE_SIZE, (map->height + 1) * IMAGE_SIZE, "So Long");
	if (!data.mlx_window)
		(sl_free_map(map), sl_error_handler(MALLOC_FAIL));
	sl_init_images(&data);
	mlx_key_hook(data.mlx_window, &sl_move_controller, &data);
	mlx_loop_hook(data.mlx_ptr, sl_display_map, &data);
	mlx_hook(data.mlx_window, 17, 0L, sl_exit, &data);
	mlx_loop(data.mlx_ptr);
	sl_free_mlx(&data);
	return (0);
}

int	main(int c, char **v)
{
	t_map	*map;

	if (c != 2)
		sl_error_handler(MISSED_ARGUMENT);
	if (!sl_endwith(v[1], ".ber"))
		sl_error_handler(INVALID_MAP_EXTENSION);
	map = sl_init_map(v[1]);
	sl_mlx_map(map);
	return (0);
}
