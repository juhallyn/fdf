/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:26:18 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/14 12:22:59 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				print_usage(void)
{
	ft_putendl_fd("usage : ./fdf map_file\x1B[32m.fdf", 2);
	ft_putstr_fd("\x1b[0m", 2);
	exit(-1);
}

void				ft_exit(char *error)
{
	if (error)
	{
		ft_putstr_fd("\x1b[31m", 2);
		ft_putendl_fd(error, 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	exit(-1);
}

int					color_mode(int z)
{
	if (z < 6 && z > 9)
		return (BLUE);
	if (z == 10)
		return (BLUE);
	if (z <= 11)
		return (GREEN);
	else
		return (RED);
}

t_segment_index		*malloc_struct_segment(void)
{
	t_segment_index *seg;

	seg = (t_segment_index*)malloc(sizeof(seg) * 2);
	if (!seg)
		ft_exit("can't allocate seg in draw_line_y");
	return (seg);
}

t_std				*return_std(t_std *std, bool flag)
{
	static t_std	*std_cpy;

	if (flag)
		std_cpy = std;
	return (std_cpy);
}
