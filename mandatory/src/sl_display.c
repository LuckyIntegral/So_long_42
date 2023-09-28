/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:18:13 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/28 19:39:10 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sl_errors.h"
#include "../inc/sl_files.h"
#include "../inc/so_long.h"

static void	put_image(t_data *data, int timing, int row, int col)
{
	void	*template;
	char	c;

	c = get_by_xy(data, row, col);
	if (c == MAP_PLAYER)
		template = data->images.sprite[(timing / 30) % KNIGHT_NUMBER];
	else if (c == MAP_COLL)
		template = data->images.coll[(timing / 30) % COLL_NUMBER];
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
		col * 64, row * 64);
}

int	sl_display_map(t_data *data)
{
	static int i = 0;
	int		col;
	int		row;

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
