/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:12:03 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/30 18:40:05 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	sl_exit_succsess(t_data *data, int moves)
{
	sl_free_mlx(data);
	ft_printf("Congrats, you have passed my mini-game!");
	ft_printf("Your final score is %d moves", moves);
	exit(0);
}

int	sl_exit(t_data *data)
{
	sl_free_mlx(data);
	exit(0);
}

void	sl_touch_enemy(t_data *data)
{
	ft_printf("Oh no, you were killed by goblins!");
	sl_exit(data);
}

void	sl_error_handler(char *status)
{
	ft_printf("Error, --- %s --- \n", status);
	exit(1);
}
