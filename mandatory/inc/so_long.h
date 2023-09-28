/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:50:22 by vfrants           #+#    #+#             */
/*   Updated: 2023/09/28 19:37:16 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libft includes:
// --- <stdlib> for: malloc, free
// --- <unistd> for: close, read, exit
# include "../../libft/ft_printf.h"
# include <fcntl.h>  // open
# include <string.h> // strerror
# include <math.h>   // math staff
# include <mlx.h>    // mlx functions

// 0 for an empty space
// C for a collectable
// E for a map exit
// P for the player’s starting position
# define MAP_ELEMENTS "10CEP"

// The same, but separatelly
# define MAP_WALL '1'
# define MAP_SPACE '0'
# define MAP_COLL 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'

// a s d w keys for sprite control, esc for exit
# define M_RIGHT 100
# define M_LEFT 97
# define M_UP 119
# define M_DOWN 115
# define ESCAPE 65307

typedef struct s_images // collect all images together
{
	void *coll[3];
	void *empty;
	// void *enemy[6];
	void *exit[2];
	void *sprite[6];
	void *wall;
}	t_images;

typedef struct s_point // just to make the code more readable
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map // map size
{
	int		width;
	int		height;
	char	*map;
}	t_map;

typedef struct s_data // instead of thousands variables
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_map		*map;
	t_point		sprite;
	t_point		exit;
	int			colls;
	t_images	images;
}	t_data;

// errors handler
void	sl_error_handler(char *status);

// move controller
int		sl_move_controller(int key, t_data *data);

// map pack
t_map	*sl_init_map(char *file);
void	sl_free_map(t_map *map);
void	sl_validate_map(t_map *map);
int		sl_does_solution_exist(t_map *map);

// util pack
void	get_element_xy(t_map *map, char search, int *x, int *y);
void	set_by_xy(t_data *data, int x, int y, char set);
void	sl_free_mlx(t_data *data);
char	get_by_xy(t_data *data, int x, int y);
int		sl_endwith(char *str, char *end);
void	sl_init_mlx_struct(t_data *data);

// close
void	sl_exit_succsess(t_data *data, int moves);
void	sl_exit_escape(t_data *data);

// helper for image initialization
void	sl_init_images(t_data *data);

// finally display on a screen
int	sl_display_map(t_data *data);

#endif
