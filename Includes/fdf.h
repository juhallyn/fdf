/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:02:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/29 18:51:17 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"

# define WIDTH 900
# define HEIGHT 900

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
	int				x_max;
	int				y_max;
}					t_std;

typedef struct		s_coord
{
	// int				x;
	// int				y;
	int				x_win;
	int				y_win;
	int				z;
}					t_coord;

/*
**	--	open_file.c --
*/

int				open_file(char *file);

/*
**	--	parse_file.c --
*/

t_coord			**malloc_coord(int x_max, int y_max);
t_coord			**parse_line(char *line, t_coord **coord, t_std *std);
t_coord			**parse_file(char *file, t_std *std);

/*
**	--	init.c --
*/

void			*init_window(void **mlx_server, int width, int height);
t_coord			**init_coord(char *file, t_std *std);
t_std			*init_std(int x_max, int y_max);

/*
**	--	check_file.c --
*/

void			check_file(char *file, int *x_max, int *y_max);

/*
**	--	tools.c --
*/

void			print_usage(void);
void			ft_exit(char *error);

#endif
