/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:01:21 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/25 17:12:56 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	sl_init_mlx_struct(t_data *data)
{
	int	col;
	int	row;

	data->mlx_ptr = NULL;
	data->mlx_window = NULL;
	get_element_xy(data->map, MAP_PLAYER, &(data->sprite.x), &(data->sprite.y));
	get_element_xy(data->map, MAP_EXIT, &(data->exit.x), &(data->exit.y));
	data->colls = 0;
	row = 1;
	while (row < data->map->height - 1)
	{
		col = 1;
		while (col < data->map->width - 1)
		{
			if (data->map->map[row * data->map->width + col] == MAP_COLL)
				data->colls++;
			col++;
		}
		row++;
	}
}

void	set_by_xy(t_data *data, int x, int y, char set)
{
	data->map->map[data->map->width * x + y] = set;
}

char	get_by_xy(t_data *data, int x, int y)
{
	return (data->map->map[(x * data->map->width) + y]);
}

void	sl_free_mlx(t_data *data)
{
	sl_free_map(data->map);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	sl_endwith(char *str, char *end)
{
	int	sstr;
	int	send;
	int	diff;

	sstr = ft_strlen(str);
	send = ft_strlen(end);
	if (sstr < send)
		return (0);
	diff = sstr - send;
	while (diff--)
		str++;
	while (*str)
	{
		if (*str != *end)
			return (0);
		str++;
		end++;
	}
	return (1);
}
