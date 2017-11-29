/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:26:18 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/29 15:31:07 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_usage(void)
{
	ft_putendl_fd("usage : ./fdf map_file\x1B[32m.fdf", 2);
	ft_putstr_fd("\x1b[0m", 2);
	exit(-1);
}

void		ft_exit(char *error)
{
	if (error)
	{
		ft_putstr_fd("\x1b[31m", 2);
		ft_putendl_fd(error, 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	exit (-1);
}
