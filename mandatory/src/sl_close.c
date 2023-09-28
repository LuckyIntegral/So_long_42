/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:19:27 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/28 20:35:57 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
