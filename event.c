/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:59:57 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/24 22:14:08 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		destroy(void)
{
	clear_memory(g_all_memories);
	exit(-1);
}

int		key_release(int key)
{
	if (key == 123 || key == 124)
		g_player.rotate_dir = 0;
	if (key == 1 || key == 13)
		g_player.walk_dir = 0;
	if (key == 2 || key == 0)
		g_player.move_side = 0;
	return (0);
}

int		event_handler(int key)
{
	if (key == 123)
		g_player.rotate_dir = -1;
	else if (key == 124)
		g_player.rotate_dir = 1;
	else if (key == 1)
		g_player.walk_dir = -1;
	else if (key == 13)
		g_player.walk_dir = 1;
	else if (key == 2)
		g_player.move_side = 1;
	else if (key == 0)
		g_player.move_side = -1;
	else if (key == 53)
		destroy();
	return (0);
}
