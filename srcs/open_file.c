/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:12:42 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/29 19:00:07 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_extension(char *filename)
{
	char	*extension;
	bool	correct;

	correct = true;
	extension = NULL;
	if ((extension = ft_strrchr(filename, '.')))
	{
		if (ft_strcmp(extension, ".fdf") != 0)
			correct = false;
	}
	if (!correct || !extension)
	{
		ft_putstr_fd("\x1b[31m", 2);
		ft_putendl_fd("Error : bad extension file", 2);
		ft_putstr_fd("\x1b[0m", 2);
		print_usage();
	}
	return (0);
}

int				open_file(char *file)
{
	int		fd;

	check_extension(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("Error during open file (Check access or if file exist)");
	return (fd);
}
