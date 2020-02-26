/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hit_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:54:52 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/24 22:16:57 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_hit_wall(float x, float y)
{
	if (x < 0 || x > (g_map_width * g_box_size) ||
		y < 0 || y > (g_map_height * g_box_size))
		return (1);
	x = floor(x / g_box_size);
	y = floor(y / g_box_size);
	return (g_world_map[(int)y][(int)x] == 1 ? 1 : 0);
}
