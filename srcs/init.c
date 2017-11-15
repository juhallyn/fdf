/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:41:02 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/15 19:14:39 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*init_window(void **mlx_server, int height, int width)
{
	void	*window;

	*mlx_server = mlx_init();
	if (!*mlx_server)
	{
		ft_putendl_fd("Can't create connexion with mlx server", 2);
		exit (-1);
	}
	window = mlx_new_window(*mlx_server, height, width, "FDF");
	if (!window)
	{
		ft_putendl_fd("Can't create new window with mlx ID", 2);
		exit (-1);
	}
	return (window);
}
