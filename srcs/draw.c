/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:56:55 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/20 20:25:31 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void		line(int x0, int y0, int x1, int y1)

void		line(void *mlx, void *win, int x_win, int y_win, int x2_win, int y2_win)
{
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int err = (dx>dy ? dx : -dy)/2, e2;

  // while (42)
  // {
  // lx_pixel_put(mlx, win, x, y, 0x0000FFFF);
  //   if (x0==x1 && y0==y1)
  // break;
  //   e2 = err;
  //   if (e2 >-dx)
  // err -= dy; x0 += sx;
  //   if (e2 < dy)
  // err += dx; y0 += sy;
  // }
}
//
// int		bresenham_test(void *mlx, void *win)
// {
// 	int		x;
// 	float	y;
//
// 	int		x1 = 0, 	y1 = 0;		//ordonne a l'origine
// 	int		x2 = 900, 	y2 = 900;	//ordonne a l'arrivee
// 	float	dx = abs(y2-y1);
// 	float	dy = abs(x2-x1);
// 	float	m = dy/dx;				// coefficient directeur (> 0);
//
// 	x = 0;
// 	y = 0;
// 	while (x < HEIGHT)
// 	{
// 		y = m * x + y1 + 0.5;
// 		mlx_pixel_put(mlx, win, x, y, 0x0000FFFF);
// 		x++;
// 	}
// 	mlx_loop(mlx);
// 	return (0);
// }
