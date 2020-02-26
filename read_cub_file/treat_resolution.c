/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 23:01:26 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 22:52:27 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	helper_function(int nb)
{
	if (nb != 2)
	{
		set_error("Error\nput just the width & height -_-\n");
		write(1, g_error_msg, ft_strlen(g_error_msg));
		exit(0);
	}
}

void		check_before_read(char *line)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (line[++i])
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
		{
			if (line[i] == ' ')
				continue;
			nb++;
			i += (skip_numbers(line + i) - 1);
		}
		else
		{
			set_error("Error\nPut just numbers Bitch -_-\n");
			write(1, g_error_msg, ft_strlen(g_error_msg));
			exit(0);
		}
	}
	helper_function(nb);
}

void		treat_resolution(char *line)
{
	int i;

	check_before_read(line);
	i = 2;
	g_file_info.win_width = ft_atoi(line + i);
	i += skip_numbers(line + i);
	g_file_info.win_height = ft_atoi(line + i + 1);
	g_file_info.win_height /= 2;
	g_file_info.win_width /= 2;
}
