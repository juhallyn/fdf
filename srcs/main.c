/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/01 17:24:50 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print_coord(t_coord **coord, t_std *std)
{
	int		i;
	int		j;

	i = 0;
	while (i < std->y_max)
	{
		j = 0;
		while (j < std->x_max)
		{
			printf("y = %d, x = %d : [%d]\n", i, j, coord[i][j].z);
			j++;
		}
		i++;
	}
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
	print_coord(coord, std);
	while (1)
	{}
	// init_std(map, x, y);
	// line(std->mlx, std->win, 20, 20, 70, 800);
	return (0);
}
