/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shot_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:54:52 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 11:03:13 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_save_param(char *str)
{
	char *save;

	save = "--save";
	if ((ft_strlen(str) != ft_strlen(save)) ||
		ft_strncmp(save, str, ft_strlen(save)))
	{
		set_error("Error\nError in the argument 3 !!\n");
		write(1, g_error_msg, ft_strlen(g_error_msg));
		exit(-1);
	}
	return (1);
}

void	is_screen_shot(int argc, char **argv)
{
	if ((argc == 3) && is_save_param(argv[2]))
	{
		g_is_screen_shot = 1;
		draw();
		create_bitmap();
		clear_memory(g_all_memories);
		exit(0);
	}
}
