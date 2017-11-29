/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:41:02 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/29 18:43:49 by juhallyn         ###   ########.fr       */
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

t_coord		**init_coord(char *file, t_std *std)
{
	t_coord		**coord;
	int			fd;
	int			y;
	char		*line;

	y = 0;
	line = NULL;
	fd = open_file(file);
	coord = malloc_coord(std->x_max, std->y_max);
	while (get_next_line(fd, &line) > 0)
	{
		coord = parse_line(line, coord, std);
		y++;
	}
}

t_std		*init_std(int x_max, int y_max)
{
	t_std	*std;
	void	*mlx;
	void	*win;

	std = NULL;
	win = NULL;
	std = (t_std*)malloc(sizeof(t_std));
	if (!std)
		ft_exit("can't allocate std in init_std");
	std->win = init_window(&mlx, WIDTH, HEIGHT);
	std->mlx = mlx;
	std->x_max = x_max;
	std->y_max = y_max;
	return (std);
}
