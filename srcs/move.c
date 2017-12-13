/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:38:51 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/13 21:09:21 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		refresh(t_coord **coord, t_std *std)
{
	mlx_clear_window(std->mlx, std->win);
	draw_line_x(coord, std);
	draw_line_y(coord, std);
}

t_coord		**up_coord_height(t_coord **coord, t_std *std)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < std->y_max)
	{
		x = 0;
		while (x < std->x_max)
		{
			if (coord[y][x].z != 0 && coord[y][x].z != 9)
				coord[y][x].y = coord[y][x].y - 10;
			x++;
		}
		y++;
	}
	return (coord);
}

t_coord		**down_coord_height(t_coord **coord, t_std *std)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < std->y_max)
	{
		x = 0;
		while (x < std->x_max)
		{
			if (coord[y][x].z != 0 && coord[y][x].z != 9)
				coord[y][x].y = coord[y][x].y + 10;
			x++;
		}
		y++;
	}
	return (coord);
}
