/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_validation_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 01:23:06 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/30 20:03:41 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/sl_errors.h"

static void	check_ceil(char **checked, int x, int y, t_map *map)
{
	if (map->map[(x * map->width) + y] == MAP_WALL)
		return ;
	if (checked[0][(x * map->width) + y] == '*')
		return ;
	checked[0][(x * map->width) + y] = '*';
	check_ceil(checked, x - 1, y, map);
	check_ceil(checked, x + 1, y, map);
	check_ceil(checked, x, y - 1, map);
	check_ceil(checked, x, y + 1, map);
}

void	get_element_xy(t_map *map, char search, int *x, int *y)
{
	int	row;
	int	col;

	row = 1;
	while (row < map->height - 1)
	{
		col = 1;
		while (col < map->width - 1)
		{
			if (map->map[row * map->width + col] == search)
			{
				*x = row;
				*y = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

int	sl_does_solution_exist(t_map *map)
{
	char	*checked;
	int		status;
	int		x;
	int		y;

	checked = ft_strdup(map->map);
	if (!checked)
	{
		sl_free_map(map);
		sl_error_handler(MALLOC_FAIL);
	}
	x = 0;
	y = 0;
	get_element_xy(map, MAP_PLAYER, &x, &y);
	check_ceil(&checked, x, y, map);
	if (ft_memchr(checked, MAP_EXIT, ft_strlen(map->map)) == NULL
		&& ft_memchr(checked, MAP_COLL, ft_strlen(map->map)) == NULL)
		status = 1;
	else
		status = 0;
	return (free(checked), status);
}
