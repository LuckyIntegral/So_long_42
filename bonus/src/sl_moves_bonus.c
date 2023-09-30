/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:25:14 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/01 01:09:04 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static int	left(t_data *data)
{
	if (get_by_xy(data, data->sprite.x, data->sprite.y - 1) == MAP_ENEMY)
		return (2);
	if (get_by_xy(data, data->sprite.x, data->sprite.y - 1) == MAP_WALL)
		return (1);
	if (data->sprite.x == data->exit.x && data->sprite.y - 1 == data->exit.y
		&& data->colls)
		return (1);
	set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x, data->sprite.y - 1) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x, data->sprite.y - 1, MAP_PLAYER);
	data->sprite.y--;
	return (0);
}

static int	right(t_data *data)
{
	if (get_by_xy(data, data->sprite.x, data->sprite.y + 1) == MAP_ENEMY)
		return (2);
	if (get_by_xy(data, data->sprite.x, data->sprite.y + 1) == MAP_WALL)
		return (1);
	if (data->sprite.x == data->exit.x && data->sprite.y + 1 == data->exit.y
		&& data->colls)
		return (1);
	set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x, data->sprite.y + 1) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x, data->sprite.y + 1, MAP_PLAYER);
	data->sprite.y++;
	return (0);
}

static int	up(t_data *data)
{
	if (get_by_xy(data, data->sprite.x - 1, data->sprite.y) == MAP_ENEMY)
		return (2);
	if (get_by_xy(data, data->sprite.x - 1, data->sprite.y) == MAP_WALL)
		return (1);
	if (data->sprite.x - 1 == data->exit.x && data->sprite.y == data->exit.y
		&& data->colls)
		return (1);
	set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x - 1, data->sprite.y) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x - 1, data->sprite.y, MAP_PLAYER);
	data->sprite.x--;
	return (0);
}

static int	down(t_data *data)
{
	if (get_by_xy(data, data->sprite.x + 1, data->sprite.y) == MAP_ENEMY)
		return (2);
	if (get_by_xy(data, data->sprite.x + 1, data->sprite.y) == MAP_WALL)
		return (1);
	if (data->sprite.x + 1 == data->exit.x && data->sprite.y == data->exit.y
		&& data->colls)
		return (1);
	set_by_xy(data, data->sprite.x, data->sprite.y, MAP_SPACE);
	if (get_by_xy(data, data->sprite.x + 1, data->sprite.y) == MAP_COLL)
		data->colls--;
	set_by_xy(data, data->sprite.x + 1, data->sprite.y, MAP_PLAYER);
	data->sprite.x++;
	return (0);
}

int	sl_move_controller(int key, t_data *data)
{
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
	if (status == 2)
		sl_touch_enemy(data);
	if (status == 0)
	{
		put_moves(data, data->moves++, 0x000000);
		put_moves(data, data->moves, 0x888888);
	}
	if (data->sprite.x == data->exit.x && data->sprite.y == data->exit.y
		&& !data->colls)
		sl_exit_succsess(data, data->moves);
	return (0);
}
