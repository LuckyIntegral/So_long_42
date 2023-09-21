/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:09:23 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/21 16:46:44 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inc/so_long.h>

void	sl_free_map(t_map *map)
{
	if (map && map->map)
		free(map->map);
	if (map)
		free(map);
}
