/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:16:01 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/06 18:12:36 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				init_origin_point(int *x0, int *y0, t_coord **coord,\
				t_segment_index *seg)
{
	*x0 = coord[seg->y0][seg->x0].x;
	*y0 = coord[seg->y0][seg->x0].y;
}

static int				init_dest_point(int *x1, int *y1, t_coord **coord,\
				t_segment_index *seg)
{
	int		color;

	color = color_mode(coord[seg->y1][seg->x1].z);
	*x1 = coord[seg->y1][seg->x1].x;
	*y1 = coord[seg->y1][seg->x1].y;
	return (color);
}

static t_segment_index	*to_real_value(int x0, int y0, int x1, int y1)
{
	t_segment_index		*seg_draw;

	seg_draw = (t_segment_index*)malloc(sizeof(seg_draw));
	if (!seg_draw)
		ft_exit("can't allocate seg_draw in to_real_value");
	seg_draw->x0 = x0;
	seg_draw->y0 = y0;
	seg_draw->x1 = x1;
	seg_draw->y1 = y1;
	return (seg_draw);
}

static void				draw_segment(t_bresenham *vars, \
						t_segment_index *seg_draw, t_std *std, int color)
{
	while (42)
	{
		mlx_pixel_put(std->mlx, std->win, seg_draw->x0, seg_draw->y0, color);
		if (seg_draw->x0 == seg_draw->x1 && seg_draw->y0 == seg_draw->y1)
			break ;
		vars->e2 = vars->err;
		if (vars->e2 > -vars->dx)
		{
			vars->err -= vars->dy;
			seg_draw->x0 += vars->sx;
		}
		if (vars->e2 < vars->dy)
		{
			vars->err += vars->dx;
			seg_draw->y0 += vars->sy;
		}
	}
	free(seg_draw);
	free(vars);
}

void					line(t_std *std, t_coord **coord, t_segment_index *seg,\
						int color)
{
	t_bresenham		*vars;
	int				x0;
	int				y0;
	int				x1;
	int				y1;

	init_origin_point(&x0, &y0, coord, seg);
	init_dest_point(&x1, &y1, coord, seg);
	vars = init_bresenham(x0, y0, x1, y1);
	draw_segment(vars, to_real_value(x0, y0, x1, y1), std, color);
	 //\
	color_mode(coord[seg->x0][seg->y0].z));
}
