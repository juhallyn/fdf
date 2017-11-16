/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/16 15:36:09 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	(void)argc;
	(void)argv;
	mlx = NULL;
	if (argc != 2)
		print_usage();
	// parse_file(argv);
	win = init_window(&mlx, HEIGHT, WIDTH);
	bresenham_test(mlx, win);
	return (0);
}

// int		main(int argc, char **argv)
// {
// 	void	*mlx;
// 	void	*win;
//
// 	int		x;
// 	float	y;
//
// 	int		x1 = 0, y1 = 0;		//ordonne a l'origine
// 	int		x2 = 900, y2 = 900;	//ordonne a l'arrivee
// 	float	dx = abs(y2-y1);
// 	float	dy = abs(x2-x1);
// 	float	m = dy/dx;			// coefficient directeur (> 0);
//
//
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 900, 900, "FDF");
//
// 	x = 0;
// 	y = 0;
// 	while (x < 900)
	// {
	// 	y = m * x + y1 + 0.5;
	// 	mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
	// 	x++;
	//
	// }
// 	mlx_loop(mlx);
// 	return (0);
// }
//
