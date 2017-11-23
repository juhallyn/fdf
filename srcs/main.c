/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 04:32:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/23 19:54:53 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void		print_list(t_map *map)
// {
// 	// if (map)
// 	// {
// 	// 	ft_putnbr(map->z);
// 	// 	ft_putchar('\n');
// 	// }
// 	while (map)
// 	{
// 		ft_putstr("x : ");
// 		ft_putnbr(map->x);
// 		ft_putchar('\t');
// 		ft_putstr("x_win : ");
// 		ft_putnbr(map->x_win);
// 		ft_putchar('\t');
// 		ft_putstr("y : ");
// 		ft_putnbr(map->y);
// 		ft_putchar('\t');
// 		ft_putstr("y_win : ");
// 		ft_putnbr(map->y_win);
// 		ft_putchar('\t');
// 		ft_putstr("z : ");
// 		ft_putnbr(map->z);
// 		ft_putchar('\n');
// 		map = map->next;
// 	}
// }

// void			print(t_map *map)
// {
// 	t_map *tmp;
// 	int x;
// 	int y;
// 	int x_right;
// 	int y_down;
//
// 	tmp = map;
//
// 	while (tmp)
// 	{
//
// 	}
// }

int				main(int argc, char **argv)
{
	t_std	*std;
	t_map	*map;
	int		x;
	int		y;

	map = NULL;
	std = NULL;
	if (argc != 2)
		print_usage();
	map = parse_file(argv[1], &x, &y);
	std = init_std(map, x, y);
	// init_matrice()
	// print_list(map);
	// win = init_window(&mlx, HEIGHT, WIDTH);
	// bresenham_test(std->mlx, std->win);
	return (0);
}
