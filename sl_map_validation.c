/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:46:20 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/21 22:34:31 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "inc/sl_errors.h"

static int	is_valid_border(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
		if (map->map[i++] != MAP_WALL)
			return (0);
	i = 0;
	while (i < map->width)
		if (map->map[i++ + (map->width * (map->height - 1))] != MAP_WALL)
			return (0);
	i = 1;
	while (i < map->height - 1)
		if (map->map[map->width * i++] != MAP_WALL)
			return (0);
	i = 1;
	while (i < map->height - 1)
		if (map->map[(map->width * i++) + (map->width - 1)] != MAP_WALL)
			return (0);
	return (1);
}

static int	is_valid_size(t_map *map)
{
	if (map->width < 3 || map->height < 3)
		return (0);
	if (map->width * map->height / map->height != map->width)
		return (0);
	if (map->width * map->height != (int)ft_strlen(map->map))
		return (0);
	return (1);
}

static int	are_valid_chars_only(t_map *map)
{
	int	row;
	int	col;

	row = 1;
	while (row < map->height - 1)
	{
		col = 1;
		while (col < map->width - 1)
			if (!ft_contains(MAP_ELEMENTS, map->map[row * map->width + col++]))
				return (0);
		row++;
	}
	return (1);
}

void	sl_validate_map(t_map *map)
{
	if (!is_valid_size(map))
	{
		sl_free_map(map);
		sl_error_handler(INVALID_MAP);
	}
	if (!is_valid_border(map))
	{
		sl_free_map(map);
		sl_error_handler(INVALID_MAP);
	}
	if (!are_valid_chars_only(map))
	{
		sl_free_map(map);
		sl_error_handler(INVALID_MAP);
	}
}
