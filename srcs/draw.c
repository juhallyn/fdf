/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:56:55 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/01 20:15:15 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_matrice(t_coord **coord, t_std *std)
{
	int		x;
	int		y;

	y = 0;
	// line(std->mlx, std->win, coord[0][0].x, coord[0][0].y,\
	// 	coord[0][1].x, coord[0][1].y);
	while (y < std->y_max)
	{
		x = 0;
		while (x < std->x_max)
		{
			mlx_pixel_put(std->mlx, std->win, coord[y][x].x, coord[y][x].y, 0x00FFFF);
			x++;
		}
		y++;
	}
}

void	draw_line(t_coord **coord, t_std *std)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y + 1 < std->y_max)
	{
		x = 0;
		while (x + 1 < std->x_max)
		{
			line(std->mlx, std->win, coord[y][x].x, coord[y][x].y, \
				coord[y][x + 1].x, coord[y][x + 1].y);
			line(std->mlx, std->win, coord[y][x].x, coord[y][x].y, \
				coord[y][x].x, coord[y + 1][x].y);
			x++;
		}
		y++;
	}
	// line(std->mlx, std->win, coord[y - 1][x].x, coord[y - 1][x].y, \
	// 	coord[y][x].x, coord[y][x].y);
	// line(std->mlx, std->win, coord[y][x - 1].x, coord[y][x - 1].y, \
	// 	coord[y][x].x, coord[y][x].y);
	mlx_loop(std->mlx);
}

void 	line(void *mlx, void *win, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	while (1)
	{
		mlx_pixel_put(mlx, win, x0, y0, 0x00FFFF);
		if (x0==x1 && y0==y1) break;
			e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}
