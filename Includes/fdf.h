/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:02:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/15 19:20:38 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"

# define HEIGHT 900
# define WIDTH 900

/*
**	--	parse.c --
*/

/*
**	--	init.c --
*/

void		*init_window(void **mlx_server, int height, int width);

/*
**	--	draw.c --
*/

int			bresenham_test(void *mlx, void *win);

#endif
