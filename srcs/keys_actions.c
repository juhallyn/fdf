/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:49:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/15 16:42:11 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int						keys_actions(int keycode, t_coord **coord)
{
	t_std		*std;

	std = return_std(NULL, false);
	if (keycode == ESC)
		exit(0);
	if (keycode == PAGE_UP)
		refresh(up_coord_height(coord, std), std);
	if (keycode == PAGE_DOWN)
		refresh(down_coord_height(coord, std), std);
	return (0);
}
