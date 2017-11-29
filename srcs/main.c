/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/29 18:45:32 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void			print_coord(t_coord **coord)
// {
// 	int		i;
//
// 	i = 0;
// 	while (coord[i])
// 	{
//
// 	}
// }

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
	// coord = parse_file(argv[1], &x_max, &y_max);
	// std = init_std(x_max, y_max);
	// print_coord(coord);
	// while (1)
	// {}
	// init_std(map, x, y);
	// line(std->mlx, std->win, 20, 20, 70, 800);
	return (0);
}
