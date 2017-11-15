/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:56:55 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/15 19:04:55 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		bresenham_test(void *mlx, void *win)
{
	int		x;
	float	y;

	int		x1 = 0, y1 = 0;		//ordonne a l'origine
	int		x2 = 900, y2 = 900;	//ordonne a l'arrivee
	float	dx = abs(y2-y1);
	float	dy = abs(x2-x1);
	float	m = dy/dx;			// coefficient directeur (> 0);

	x = 0;
	y = 0;
	while (x < HEIGHT)
	{
		y = m * x + y1 + 0.5;
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
