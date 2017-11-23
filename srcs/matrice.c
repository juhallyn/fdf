/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:32:32 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/23 20:15:47 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int		**insert_data_matrice(t_map *map, int **tab)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (map)
	{
		if (y < map->y)
		{
			y++;
			x = 0;
		}
		tab[y][x] = map->z;
		x++;
		map = map->next;
	}
	return (tab);
}

int				**malloc_matrice(t_map *map, int x, int y)
{
	int		**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = NULL;
	tab = (int**)malloc(sizeof(int*) * (y));
	while (i < y)
	{
		tab[i] = (int*)malloc(sizeof(int) * (x));
		printf("line = %d\nx = %d\n", i, x);
		i++;
	}
	// if (!tab)
	// 	ft_exit("Can't allocate tab (y) in create_matrice");
	// while (i < y)
	// {
	// 	tab[i] = (int*)malloc(sizeof(int*) * x + 4);
	// 	// if (!tab[i])
	// 	// 	ft_exit("Can't allocate tab (x) in create_matrice");
	// 	i++;
	// }
	tab = insert_data_matrice(map, tab);
	print_tab(tab, x, y);
	return (tab);
}


int		print_tab(int **tab, int x, int y)
{
	int i, j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("tab[%d][%d] %d \n",i, j, tab[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
