/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:26:18 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/16 17:18:04 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_usage(void)
{
	ft_putendl_fd("usage : ./fdf map_file\x1B[32m.fdf\x1B[0m", 2);
	exit(-1);
}
