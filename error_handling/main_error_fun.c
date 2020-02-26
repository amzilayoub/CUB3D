/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:38:37 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 15:24:01 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

void	init_error(void)
{
	g_error = 0;
	g_error_msg = NULL;
}

void	set_error(char *msg)
{
	g_error = 1;
	g_error_msg = msg;
}

void	check_if_error(void)
{
	if (g_error)
	{
		write(1, g_error_msg, ft_strlen(g_error_msg));
		clear_memory(g_all_memories);
		exit(-1);
	}
}

void	main_error_fun(void)
{
	int i;

	i = -1;
	if (g_player.nb_player != 1)
		set_error("Error\nZero or more than 2 Players in the MAP !!\n");
	while (++i < 8)
		if (g_duplicate[i] != 1)
			set_error("Error\nDuplicate element in the info.cub !!\n");
	check_if_error();
	check_the_resolution();
	check_if_error();
	check_textures();
	check_if_error();
	check_the_map();
	check_if_error();
	check_the_rgb();
}
