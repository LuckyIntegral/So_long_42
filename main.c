/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:38:47 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/24 22:46:45 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "inc/sl_errors.h"

static void	sl_put_map(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->map->height)
	{
		col = 0;
		while (col < data->map->width)
		{
			ft_printf("%c", get_by_xy(data, col, row));
			col++;
		}
		ft_printf("\n");
		row++;
	}
	ft_printf("\n");
}

static int	sl_mlx_map(t_map *map)
{
	t_data	data;

	sl_init_mlx_struct(&data);
	data.map = map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		(sl_free_map(map), sl_error_handler(MALLOC_FAIL));
	data.mlx_window = mlx_new_window(data.mlx_ptr, 1000, 500, "So Long");
	if (!data.mlx_window)
		(sl_free_mlx(&data), sl_error_handler(MALLOC_FAIL));
	mlx_key_hook(data.mlx_window, &sl_move_controller, &data);
	sl_put_map(&data);
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
