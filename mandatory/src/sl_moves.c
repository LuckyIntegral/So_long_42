/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:25:14 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/28 20:36:30 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	left(t_data *data)
{
	if (get_by_xy(data, data->sprite.x, data->sprite.y - 1) == MAP_WALL)
		return (1);
	if (data->sprite.x == data->exit.x && data->sprite.y == data->exit.y)
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_EXIT);
	else
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x, data->sprite.y - 1) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x, data->sprite.y - 1, MAP_PLAYER);
	data->sprite.y--;
	return (0);
}

static int	right(t_data *data)
{
	if (get_by_xy(data, data->sprite.x, data->sprite.y + 1) == MAP_WALL)
		return (1);
	if (data->sprite.x == data->exit.x && data->sprite.y == data->exit.y)
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_EXIT);
	else
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x, data->sprite.y + 1) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x, data->sprite.y + 1, MAP_PLAYER);
	data->sprite.y++;
	return (0);
}

static int	up(t_data *data)
{
	if (get_by_xy(data, data->sprite.x - 1, data->sprite.y) == MAP_WALL)
		return (1);
	if (data->sprite.x == data->exit.x && data->sprite.y == data->exit.y)
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_EXIT);
	else
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x - 1, data->sprite.y) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x - 1, data->sprite.y, MAP_PLAYER);
	data->sprite.x--;
	return (0);
}

static int	down(t_data *data)
{
	if (get_by_xy(data, data->sprite.x + 1, data->sprite.y) == MAP_WALL)
		return (1);
	if (data->sprite.x == data->exit.x && data->sprite.y == data->exit.y)
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_EXIT);
	else
		set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x + 1, data->sprite.y) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x + 1, data->sprite.y, MAP_PLAYER);
	data->sprite.x++;
	return (0);
}

int	sl_move_controller(int key, t_data *data)
{
	static int	moves = 0;
	int			status;

	if (key == ESCAPE)
		sl_exit(data);
	status = -1;
	if (key == M_RIGHT)
		status = right(data);
	else if (key == M_DOWN)
		status = down(data);
	else if (key == M_LEFT)
		status = left(data);
	else if (key == M_UP)
		status = up(data);
	if (status == 0)
		ft_printf("Moves: %d\n", ++moves);
	if (data->sprite.x == data->exit.x && data->sprite.y == data->exit.y
		&& !data->colls)
		sl_exit_succsess(data, moves);
	return (0);
}
