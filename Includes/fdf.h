/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:02:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/16 16:37:01 by juhallyn         ###   ########.fr       */
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

# define HEIGHT 900
# define WIDTH 900

/*
**	--	open_file.c --
*/


int				open_file(char *file);

// void			parse_file(char *file);
/*
**	--	init.c --
*/

void			*init_window(void **mlx_server, int width, int height);

/*
**	--	draw.c --
*/

int				bresenham_test(void *mlx, void *win);

/*
**	--	tools.c --
*/

void			print_usage(void);

#endif
