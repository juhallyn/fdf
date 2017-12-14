/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:48:30 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/14 15:10:46 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
