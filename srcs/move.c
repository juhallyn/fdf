/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:38:51 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/14 17:28:32 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_move		*malloc_move_pos(t_std *std)
{
	t_move	**move_pos;
	int		i;

	i = 0;
	move_pos = NULL;
	move_pos = (t_move**)malloc(sizeof(move_pos) * std->y_max);
	if (!move_pos)
		ft_exit("can't allocate move_pos in keys_actions");
	while (i < (y_max + 1))
	{
		move_pos[i] = (t_move*)malloc(sizeof(move_pos) * std->x_max);
		if (!move_pos[i])
			ft_exit("can't allocate move_pos (for x) in move");
		i++;
	}
	return (move_pos);
}

t_coord		**move_up(t_coord **coord, t_std *std, int up, t_move ***mv)
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
			coord[y][x].x = ((INIT_X) + (SUB_WIDTH / std->x_max) \
			* sqrt(2) / 2 * (x - y));
			coord[y][x].y = ((INIT_Y * 0.2 + up) + (SUB_HEIGHT / std->y_max) * \
			(-(sqrt(2.0 / 3) * coord[y][x].z - (1 / sqrt(6)) * (x + y))));
			mv[y][x]->init_x = INIT_X;
			mv[y][x]->init_y = (INIT_Y * 0.2 + up);
			x++;
		}
		y++;
	}
	return (coord);
}

t_coord		**move_down(t_coord **coord, t_std *std, int up, t_move ***mv)
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
			coord[y][x].x = ((INIT_X) + (SUB_WIDTH / std->x_max) \
			* sqrt(2) / 2 * (x - y));
			coord[y][x].y = ((INIT_Y * 0.5 + up) + (SUB_HEIGHT / std->y_max) * \
			(-(sqrt(2.0 / 3) * coord[y][x].z - (1 / sqrt(6)) * (x + y))));
			mv[y][x]->init_x = INIT_X;
			mv[y][x]->init_y = (INIT_Y * 0.2 + up);
			x++;
		}
		y++;
	}
	return (coord);
}

t_coord		**move_right(t_coord **coord, t_std *std, int up, t_move ***mv)
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
			coord[y][x].x = ((INIT_X) + (SUB_WIDTH / std->x_max) \
			* sqrt(2) / 2 * (x - y));
			coord[y][x].y = ((INIT_Y + up) + (SUB_HEIGHT / std->y_max) * \
			(-(sqrt(2.0 / 3) * coord[y][x].z - (1 / sqrt(6)) * (x + y))));
			x++;
		}
		y++;
	}
	return (coord);
}
