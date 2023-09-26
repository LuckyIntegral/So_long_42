/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:38:47 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/26 17:39:28 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "inc/sl_errors.h"

static int	mlx_display_map(t_data *data)
{
	int ipx = 32;
	int sl = 100;
	int es = 100;
	void *image = mlx_new_image(data->mlx_ptr, 100, 100);
	void *picture = mlx_get_data_addr(image, &ipx, &sl, &es);
	mlx_xpm_to_image
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, picture, 20, 30);
	return (0);
}

static int	sl_mlx_map(t_map *map)
{
	t_data	data;

	data.map = map;
	sl_init_mlx_struct(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		(sl_free_map(map), sl_error_handler(MALLOC_FAIL));
	data.mlx_window = mlx_new_window(data.mlx_ptr, 1000, 500, "So Long");
	if (!data.mlx_window)
		(sl_free_mlx(&data), sl_error_handler(MALLOC_FAIL));
	mlx_key_hook(data.mlx_window, &sl_move_controller, &data);
	sl_put_map(&data);
	mlx_loop_hook(data.mlx_ptr, mlx_display_map, &data);
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
	return (1);
}
