/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:18:13 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/30 18:37:13 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sl_errors_bonus.h"
#include "../inc/sl_files_bonus.h"
#include "../inc/so_long_bonus.h"

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

static void	put_image(t_data *data, int timing, int row, int col)
{
	void	*template;
	char	c;

	c = get_by_xy(data, row, col);
	if (c == MAP_PLAYER)
		template = data->images.sprite[(timing / 30) % KNIGHT_NUMBER];
	else if (c == MAP_COLL)
		template = data->images.coll[(timing / 30) % COLL_NUMBER];
	else if (c == MAP_ENEMY)
		template = data->images.enemy[(timing / 30) % ENEMY_NUMBER];
	else if (c == MAP_EXIT)
	{
		if (data->colls)
			template = data->images.exit[1];
		else
			template = data->images.exit[0];
	}
	else if (c == MAP_WALL)
		template = data->images.wall;
	else
		template = data->images.empty;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, template,
		col * IMAGE_SIZE, row * IMAGE_SIZE);
}

int	sl_display_map(t_data *data)
{
	static int	i = 0;
	int			col;
	int			row;

	col = 0;
	while (col < data->map->width)
	{
		row = 0;
		while (row < data->map->height)
		{
			put_image(data, i, row, col);
			row++;
		}
		col++;
	}
	i++;
	if (i == 1800)
		i = 0;
	return (0);
}
