/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:06 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/05 19:43:03 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord				**malloc_coord(int x_max, int y_max)
{
	t_coord		**coord;
	int			i;

	i = 0;
	coord = (t_coord**)malloc(sizeof(t_coord) * (y_max));
	if (!coord)
		ft_exit("can't allocate coord (for y) in parse_file");
	while (i < (y_max + 1))
	{
		coord[i] = (t_coord*)malloc(sizeof(t_coord) * (x_max));
		if (!coord[i])
			ft_exit("can't allocate coord (for x) in parse_file");
		i++;
	}
	return (coord);
}

t_coord				**parse_line(char *line, int y, t_coord **coord, t_std *std)
{
	char	**split;
	int		x;

	x = 0;
	split = ft_strsplit(line, ' ');
	while (split[x])
	{
		coord[y][x].z = ft_atoi(split[x]);
		coord[y][x].x = (INIT_X + (SUB_WIDTH / std->x_max) * sqrt(2) / 2 * (x - y));
		coord[y][x].y = (INIT_Y + (SUB_HEIGHT / std->y_max) * \
		(-(sqrt(2.0/3) * coord[y][x].z - (1/sqrt(6)) * (x + y))));
		x++;
	}
	ft_arraydel(&split);
	return (coord);
}

t_coord			**parse_file(char *file, t_std *std)
{
	t_coord		**coord;

	coord = init_coord(file, std);
	return (coord);
}
