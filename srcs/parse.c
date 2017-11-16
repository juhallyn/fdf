/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:18:06 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/16 18:12:15 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			init_struct(char *altitude, int x, int y)
{

}

static void			parse_line(char *line, int y)
{
	char	**split;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
	{
		init_struct()
	}
}

void				parse_file(char *file)
{
	int		fd;
	char	*line;
	int		y;

	fd = open_file(file);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		parse_line(line, y);
	}
}

// static int		open_file(char *file)
// {
//
