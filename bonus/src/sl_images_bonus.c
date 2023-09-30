/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_images_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:41:39 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/30 18:30:53 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sl_errors_bonus.h"
#include "../inc/sl_files_bonus.h"
#include "../inc/so_long_bonus.h"

static void	sl_set_all_null(t_images *images)
{
	int	i;

	i = 0;
	while (i < 3)
		images->coll[i++] = NULL;
	i = 0;
	while (i < 2)
		images->exit[i++] = NULL;
	i = 0;
	while (i < 6)
		images->sprite[i++] = NULL;
	images->empty = NULL;
	images->wall = NULL;
}

static int	init_coll_empty_exit(void *mlx, t_images *images, int *x, int *y)
{
	const char	*enemy[] = {ENEMY_0, ENEMY_1, ENEMY_2, ENEMY_3,
		ENEMY_4, ENEMY_5};
	const char	*coll[] = {COLL_0, COLL_1, COLL_2};
	int			i;

	i = 0;
	while (i < 3)
	{
		images->coll[i] = mlx_xpm_file_to_image(mlx, (char *)coll[i], x, y);
		if (!images->coll[i])
			return (1);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		images->enemy[i] = mlx_xpm_file_to_image(mlx, (char *)enemy[i], x, y);
		if (!images->enemy[i])
			return (1);
		i++;
	}
	images->empty = mlx_xpm_file_to_image(mlx, EMPTY_0, x, y);
	if (!images->empty)
		return (1);
	return (0);
}

static int	init_sprite_wall_enemy(void *mlx, t_images *images, int *x, int *y)
{
	const char	*sprite[] = {KNIGHT_0, KNIGHT_1, KNIGHT_2, KNIGHT_3,
		KNIGHT_4, KNIGHT_5};
	const char	*exit[] = {EXIT_0, EXIT_1};
	int			i;

	i = 0;
	while (i < 6)
	{
		images->sprite[i] = mlx_xpm_file_to_image(mlx, (char *)sprite[i], x, y);
		if (!images->sprite[i])
			return (1);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		images->exit[i] = mlx_xpm_file_to_image(mlx, (char *)exit[i], x, y);
		if (!images->exit[i])
			return (1);
		i++;
	}
	images->wall = mlx_xpm_file_to_image(mlx, WALL_0, x, y);
	if (!images->wall)
		return (1);
	return (0);
}

static void	failed_image(t_data *data)
{
	sl_free_mlx(data);
	sl_error_handler(WRONG_TEXTURE_PATH);
}

void	sl_init_images(t_data *data)
{
	int			x;
	int			y;

	x = 64;
	y = 64;
	sl_set_all_null(&data->images);
	if (init_coll_empty_exit(data->mlx_ptr, &(data->images), &x, &y))
		failed_image(data);
	if (init_sprite_wall_enemy(data->mlx_ptr, &(data->images), &x, &y))
		failed_image(data);
}
