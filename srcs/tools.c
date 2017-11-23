/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:26:18 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/23 19:54:53 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_usage(void)
{
	ft_putendl_fd("usage : ./fdf map_file\x1B[32m.fdf\x1B[0m", 2);
	exit(-1);
}

void		ft_exit(char *error)
{
	if (error)
		ft_putendl_fd(error, 2);
	exit (-1);
}
