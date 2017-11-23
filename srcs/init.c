/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:41:02 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/23 19:54:52 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*init_window(void **mlx_server, int width, int height)
{
	void	*window;

	*mlx_server = mlx_init();
	if (!*mlx_server)
		ft_exit("Can't create connexion with mlx server");
	window = mlx_new_window(*mlx_server, width, height, "FDF");
	if (!window)
		ft_exit("Can't create new window with mlx ID");
	return (window);
}

t_std		*init_std(t_map *map, int x, int y)
{
	t_std	*std;
	void	*mlx;
	void	*win;

	mlx = NULL;
	win = NULL;
	std = NULL;
	std = (t_std*)malloc(sizeof(t_std));
	if (!std)
		ft_exit("Can't allocate std struct in init_std");
	// win = init_window(&mlx, WIDTH, HEIGHT);
	std->mlx = mlx;
	std->win = win;
	std->tab = malloc_matrice(map, x, y);
	return (std);
}
