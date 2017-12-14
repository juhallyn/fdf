/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/14 15:56:15 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord			**refresh(t_coord **coord, t_std *std)
{
	mlx_clear_window(std->mlx, std->win);
	draw_line_x(coord, std);
	draw_line_y(coord, std);
	return (coord);
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
	mlx_key_hook(std->win, &keys_actions, coord);
	draw_line_x(coord, std);
	draw_line_y(coord, std);
	mlx_loop(std->mlx);
	return (0);
}
