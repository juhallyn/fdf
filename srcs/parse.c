/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:06 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/29 19:00:28 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord				**malloc_coord(int x_max, int y_max)
{
	t_coord		**coord;
	int			i;

	i = 0;
	coord = (t_coord**)malloc(sizeof(t_coord*) * (y_max + 1));
	if (!coord)
		ft_exit("can't allocate coord (for y) in parse_file");
	while (coord[i])
	{
		coord[i] = (t_coord*)malloc(sizeof(t_coord*) * (x_max + 1));
		if (!coord[i])
			ft_exit("can't allocate coord (for x) in parse_file");
		i++;
	}
	return (coord);
}

t_coord				**parse_line(char *line, t_coord **coord, t_std *std)
{
	char	**split;
	int		x;
	int		z;

	x = 0;
	split = ft_strsplit(line, ' ');
	while (split[x])
	{
		line_coord[y][x].z = ft_atoi(split[x]);
		// line_coord[y][x].x_win = (INIT_X + (SUB_WIDTH / x_max) * x);
		// line_coord[y][x].y_win = INIT_Y + (SUB_HEIGHT / y_max) * node->y - \
	// 	(SUB_HEIGHT / Y_MAX) * node->z);
		x++;
	}
	ft_arraydel(&split);
	return (NULL);
}

t_coord				**parse_file(char *file, t_std *std)
{
	t_coord		**coord;
	char		*line;
	int			i;

	i = 0;
	coord = init_coord(file, std);
	return (coord);
}
