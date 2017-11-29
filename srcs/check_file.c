/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:15:12 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/29 18:54:43 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			count_coord_by_line(char *line)
{
	char	**split;
	int		nb_coord;
	int		j;

	j = 0;
	nb_coord = 0;
	split = ft_strsplit(line, ' ');
	if (!split[1])
	{
		ft_arraydel(&split);
		ft_exit("map_error: the coord will be separed by space character(s)");
	}
	while (split[nb_coord])
	{
		while (split[nb_coord][j])
		{
			if (ft_isdigit(split[nb_coord][j]) != 1)
				ft_exit("map_error : invalid character(s) in file");
			j++;
		}
		++nb_coord;
	}
	--nb_coord;
	ft_arraydel(&split);
	return (nb_coord);
}

void			check_file(char *file, int *x_max, int *y_max)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open_file(file);
	if (get_next_line(fd, &line) > 0)
	{
		*x_max = count_coord_by_line(line);
		ft_strdel(&line);
	}
	else
		ft_exit("Error during reading file");
	while (get_next_line(fd, &line) > 0)
	{
		if (*x_max != count_coord_by_line(line))
			ft_exit("map_error : invalid map size");
		ft_strdel(&line);
		*y_max = *y_max + 1;
	}
	close(fd);
}
