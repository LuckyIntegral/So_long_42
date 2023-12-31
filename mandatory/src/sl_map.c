/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:03:11 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/28 19:16:57 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sl_errors.h"
#include "../inc/so_long.h"

static void	failed_malloc(char *str, t_map *map, int fd)
{
	close(fd);
	free(str);
	sl_free_map(map);
	sl_error_handler(MALLOC_FAIL);
}

static void	map_cat(t_map *map, char *buffer, int fd)
{
	char	*temp;
	char	*res;

	if (map->map)
	{
		temp = map->map;
		res = ft_strjoin(map->map, buffer);
		if (!res)
			failed_malloc(buffer, map, fd);
		map->map = res;
		free(temp);
	}
	else
	{
		res = ft_strdup(buffer);
		if (!res)
			failed_malloc(buffer, map, fd);
		map->map = res;
	}
	map->height++;
}

static t_map	*parse_map(int fd)
{
	t_map	*map;
	char	*buffer;
	char	*trimmed;

	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	buffer = get_next_line(fd);
	if (!buffer)
		return (free(map), NULL);
	map->width = ft_strlen(buffer) - 1;
	map->height = 0;
	while (buffer)
	{
		trimmed = ft_strtrim(buffer, "\n");
		if (!trimmed)
			failed_malloc(buffer, map, fd);
		free(buffer);
		if ((int)ft_strlen(trimmed) != map->width)
			failed_malloc(trimmed, map, fd);
		map_cat(map, trimmed, fd);
		free(trimmed);
		buffer = get_next_line(fd);
	}
	return (map);
}

t_map	*sl_init_map(char *file)
{
	t_map	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sl_error_handler(INVALID_MAP_PATH);
	map = parse_map(fd);
	close(fd);
	if (!map)
		sl_error_handler(MALLOC_FAIL);
	sl_validate_map(map);
	return (map);
}

void	sl_free_map(t_map *map)
{
	if (map->map)
		free(map->map);
	if (map)
		free(map);
}
