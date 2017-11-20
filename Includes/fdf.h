/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:02:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/20 20:20:21 by juhallyn         ###   ########.fr       */
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

# define SUB_WIDTH 1720
# define SUB_HEIGHT 980

# define INIT_X 100
# define INIT_Y 50

# define X_MAX 18
# define Y_MAX 10

/*
**	--	struct --
*/

typedef struct		s_map
{
	int				x;
	int				y;
	int				x_win;
	int				y_win;
	int				z;
	struct s_map	*next;
}					t_map;

/*
**			--	functions --
*/

/*
**	--	open_file.c --
*/

int				open_file(char *file);

/*
**	--	parse_file.c --
*/

t_map			*parse_file(char *file);

/*
**	--	init.c --
*/

void			*init_window(void **mlx_server, int width, int height);

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
