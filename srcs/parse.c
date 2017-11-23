/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:06 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/23 18:01:54 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			parse_line(t_map **map, char *line, int y)
{
	char	**split;
	int		z;
	size_t	x;

	x = 0;
	z = 0;
	split = ft_strsplit(line, ' ');
	while (split[x])
	{
		z = ft_atoi(split[x]);
		add_end(map, z, x, y);
		x++;
	}
	return (x);
}

t_map			*parse_file(char *file, int *x, int *y)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = NULL;
	*y = 0;
	fd = open_file(file);
	if (get_next_line(fd, &line) > 0)
	{
		*x = parse_line(&map, line, *y);
		*y = *y + 1;
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (*x != parse_line(&map, line, *y))
			ft_exit("map error : invalide number of x element");
		*y = *y + 1;
	}
	close(fd);
	return (map);
}
