/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/06 16:34:44 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				exit_win(int keycode)
{
	if (keycode == 53)
		exit(1);
	return (0);
}
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
	mlx_key_hook(std->win, &exit_win, NULL);
	draw_line_x(coord, std);
	draw_line_y(coord, std);
	mlx_loop(std->mlx);
	return (0);
}
