/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:56:55 by juhallyn          #+#    #+#             */
/*   Updated: 2017/12/14 11:15:10 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				draw_line_x(t_coord **coord, t_std *std)
{
	t_segment_index *seg;

	seg = malloc_struct_segment();
	seg->x0 = 0;
	seg->y0 = 0;
	while (seg->y0 < std->y_max)
	{
		seg->x0 = 0;
		while (seg->x0 + 1 < std->x_max)
		{
			seg->x0++;
			seg->y1 = seg->y0;
			seg->x1 = (seg->x0 - 1);
			line(std, coord, seg, color_mode(coord[seg->y1][seg->x1].z));
		}
		seg->y0++;
	}
	free(seg);
}

void				draw_line_y(t_coord **coord, t_std *std)
{
	t_segment_index *seg;

	seg = malloc_struct_segment();
	seg->x0 = 0;
	seg->y0 = 0;
	while (seg->y0 + 1 < std->y_max)
	{
		seg->x0 = 0;
		while (seg->x0 + 1 < std->x_max)
		{
			seg->y1 = seg->y0 + 1;
			seg->x1 = seg->x0;
			line(std, coord, seg, color_mode(coord[seg->y1][seg->x1].z));
			seg->x0++;
		}
		seg->y0++;
		if (seg->y0 + 1 <= std->y_max && seg->x0 + 1 <= std->x_max)
		{
			seg->y1 = seg->y0 - 1;
			seg->x1 = seg->x0;
			line(std, coord, seg, color_mode(coord[seg->y1][seg->x1].z));
		}
	}
	free(seg);
}
