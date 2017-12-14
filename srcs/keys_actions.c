/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:49:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/14 16:59:49 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline void 	up_action(t_coord **coord, t_std *std, int up, t_move ***mv)
{
	coord = move_up(coord, std, up);
	refresh(coord, std);
}

static inline void 	down_action(t_coord **coord, t_std *std, int up,\
	 				t_move ***mv)
{
	coord =	move_down(coord, std, up);
	refresh(coord, std);
}

int					keys_actions(int keycode, t_coord **coord)
{
	static int	up = 200;
	t_std		*std;
	t_move		*move_pos;

	move_pos = malloc_move_pos(std);
	std = return_std(NULL, false);
	if (keycode == ESC)
		exit(0);
	if (keycode == PAGE_UP)
		refresh(up_coord_height(coord, std), std);
	if (keycode == PAGE_DOWN)
		refresh(down_coord_height(coord, std), std);
	if (keycode == UP_ARROW)
	{
		up_action(coord, std, up);
		up = up - 100;
	}
	if (keycode == DOWN_ARROW)
	{
		down_action(coord, std, up);
		up = up + 100;
	}
	if (keycode == RIGHT_ARROW)
	{
		coord = move_right(coord, std, up);
		refresh(coord, std);
	}
	else
		printf("key : %d\n", keycode);
	// if (keycode == LEFT_ARROW)
	return (0);
}
