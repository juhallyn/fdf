/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/16 16:39:08 by juhallyn         ###   ########.fr       */
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
	open_file(argv[1]);
	ft_putendl(argv[1]);
	win = init_window(&mlx, HEIGHT, WIDTH);
	bresenham_test(mlx, win);
	return (0);
}
