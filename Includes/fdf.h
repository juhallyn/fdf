/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:02:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/23 19:56:40 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include "./logger/incs/logger_utils.h" //DEBUG
// # include "./logger/incs/logger.h"		//DEBUG

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

# define WIDTH 1920
# define HEIGHT 1080

# define SUB_HEIGHT 1720
# define SUB_WIDTH 980

# define INIT_X 100
# define INIT_Y 50

/*
**	--	struct --
*/


typedef struct		s_std
{
	void			*mlx;
	void			*win;
	int				**tab;
}					t_std;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
	// int				x_win;
	// int				y_win;
	struct s_map	*next;
}					t_map;

/*
**	--	open_file.c --
*/

int				open_file(char *file);

/*
**	--	parse_file.c --
*/

t_map			*parse_file(char *file, int *x, int *y);

/*
**	--	init.c --
*/

void			*init_window(void **mlx_server, int width, int height);
t_std			*init_std(t_map *map, int x, int y);

/*
**	--	matrice.c --
*/

int				**malloc_matrice(t_map *map, int x, int y);

/*
**	--	draw.c --
*/

int				bresenham_test(void *mlx, void *win);

/*
**	--	list.c --
*/

void			add_end(t_map **map, int z, int x, int y);

/*
**	--	tools.c --
*/

void			print_usage(void);
void			ft_exit(char *error);

#endif
