/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:55:42 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/23 19:54:52 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static t_map		*create_node(int z, int x, int y)
{
	t_map	*node;

	node = (t_map*)malloc(sizeof(t_map));
	if (!node)
		ft_exit("can't allocate node in create_node");
	node->x = x;
	node->y = y;
	node->z = z;
	// node->x_win = (INIT_X + (SUB_WIDTH / X_MAX) * node->x);
	// node->y_win = (INIT_Y + (SUB_HEIGHT / Y_MAX) * node->y - \
	// 	(SUB_HEIGHT / Y_MAX) * node->z);
	node->next = NULL;
	return (node);
}

void				add_end(t_map **map, int z, int x, int y)
{
	t_map	*tmp;

	tmp = NULL;
	if (!*map)
		*map = create_node(z, x, y);
	else
	{
		tmp = *map;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = create_node(z, x, y);
	}
}
