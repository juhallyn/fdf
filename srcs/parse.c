/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:06 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/20 20:10:20 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void			parse_line(t_map **map, char *line, int y)
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
}

t_map			*parse_file(char *file)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		y;

	map = NULL;
	y = 0;
	fd = open_file(file);
	while (get_next_line(fd, &line) > 0)
	{
		parse_line(&map, line, y);
		y++;
	}
	return (map);
}

// static int		open_file(char *file)
// {
//
