/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:50:22 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/21 17:41:37 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libft includes:
// --- <stdlib> for: malloc, free
// --- <unistd> for: close, read, exit
# include "../libft/ft_printf.h"
# include <fcntl.h>  // open
# include <string.h> // strerror
# include <math.h>   // math staff
# include <mlx.h>    // mlx functions

// 0 for an empty space
// C for a collectible
// E for a map exit
// P for the player’s starting position
# define MAP_ELEMENTS "10CEP"

// 1 for a wall
# define MAP_WALL '1'

typedef struct s_map // map size
{
	size_t	width;
	size_t	height;
	char	*map;
}	t_map;

// errors handler
void	sl_error_handler(int status);

// map pack
char	*sl_init_map(char *file);
void	sl_free_map(t_map *map);
void	sl_validate_map(t_map *map);

// util pack
int		sl_contains(const char *str, char c);
int		sl_endwith(char *str, char *end);


#endif
