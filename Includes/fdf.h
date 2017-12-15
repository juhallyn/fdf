/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:02:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/15 16:41:05 by juhallyn         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080

// # define SUB_HEIGHT 500
// # define SUB_WIDTH 1080

# define SUB_HEIGHT 400
# define SUB_WIDTH 1070

# define INIT_X 850
# define INIT_Y 500

/*
**	--	KEYS  --
*/

# define PAGE_DOWN 121
# define PAGE_UP 116
# define ESC 53
# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124

/*
**	--	colors  --
*/

# define RED 0x78201E
# define BLUE 0x00FFFF
# define GREEN 0x2DB92D


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
	int				x;
	int				y;
	int				z;
}					t_coord;

/*
**	--	vars for bresenham algoritm --
**				|
**				V
*/

typedef struct		s_bresenham
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_bresenham;

/*
**	--	index_coord of segment  --
**
**		this struct will be contain
**		the real value in line()
*/

typedef struct		s_segment_index
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_segment_index;

/*
**	--	main.c --
*/

void			refresh(t_coord **coord, t_std *std);

/*
**	--	open_file.c --
*/

int				open_file(char *file);

/*
**	--	parse_file.c --
*/

t_coord			**malloc_coord(int x_max, int y_max);
t_coord			**parse_line(char *line, int y, t_coord **coord, t_std *std);
t_coord			**parse_file(char *file, t_std *std);

/*
**	--	init.c --
*/

void			*init_window(void **mlx_server, int width, int height);
t_coord			**init_coord(char *file, t_std *std);
t_std			*init_std(int x_max, int y_max);
t_bresenham		*init_bresenham(int x0, int y0, int x1, int y1);

/*
**	--	check_file.c --
*/

void			check_file(char *file, int *x_max, int *y_max);

/*
**	--	tools.c --
*/

void				print_usage(void);
void				ft_exit(char *error);
int					color_mode(int z);
t_segment_index		*malloc_struct_segment(void);
t_std				*return_std(t_std *std, bool flag);

/*
**	--	draw.c --
*/

void			draw_line_x(t_coord **coord, t_std *std);
void			draw_line_y(t_coord **coord, t_std *std);

/*
**	--	bresenham.c --
*/

void 			line(t_std *std, t_coord **coord, t_segment_index *seg, int color);

/*
**	--	up_down_coord.c --
*/

t_coord			**up_coord_height(t_coord **coord, t_std *std);
t_coord			**down_coord_height(t_coord **coord, t_std *std);

/*
**	--	keys_actions.c --
*/

int				keys_actions(int keycode, t_coord **coord);

#endif
