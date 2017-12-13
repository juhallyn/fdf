/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/13 21:06:22 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				key_action(int keycode, t_coord **coord)
{
	t_std		*std;

	std = return_std(NULL, false);
	if (keycode == ESC)
		exit(1);
	if (keycode == PAGE_UP)
	{
		coord = up_coord_height(coord, std);
		refresh(coord, std);
	}
	if (keycode == PAGE_DOWN)
	{
		coord = down_coord_height(coord, std);
		refresh(coord, std);
	}
	else
		printf("key : %d\n", keycode);
	return (0);
}

int				main(int argc, char **argv)
{
	int			x_max;
	int			y_max;
	t_coord		**coord;
	t_std		*std;

	x_max = 0;
	y_max = 0;
	if (argc != 2)
		print_usage();
	check_file(argv[1], &x_max, &y_max);
	std = init_std(x_max, y_max);
	coord = parse_file(argv[1], std);
	mlx_key_hook(std->win, &key_action, coord);
	draw_line_x(coord, std);
	draw_line_y(coord, std);
	mlx_loop(std->mlx);
	return (0);
}
