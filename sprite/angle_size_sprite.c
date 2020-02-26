/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:35:28 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 10:40:56 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	angle_size_sprite(int i)
{
	while (g_sprites[i].angle - g_player.rotate_angle > M_PI)
		g_sprites[i].angle -= 2 * M_PI;
	while (g_sprites[i].angle - g_player.rotate_angle < -M_PI)
		g_sprites[i].angle += 2 * M_PI;
	if (g_file_info.win_width >= g_file_info.win_height)
		g_sprites[i].size = (g_file_info.win_width /
				g_sprites[i].dist * g_box_size);
	else
		g_sprites[i].size = (g_file_info.win_height /
							g_sprites[i].dist * g_box_size);
}
