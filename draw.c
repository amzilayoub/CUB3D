/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:23:09 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 11:28:11 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw(void)
{
	float steps;
	float x;
	float y;

	g_player.rotate_angle += RAD(g_player.rotate_speed * g_player.rotate_dir);
	steps = g_player.walk_speed * (float)g_player.walk_dir;
	x = cos(g_player.rotate_angle) * steps;
	y = sin(g_player.rotate_angle) * steps;
	x += (g_player.move_side * g_player.walk_speed) *
		cos(RAD(90) + g_player.rotate_angle);
	y += (g_player.move_side * g_player.walk_speed) *
		sin(RAD(90) + g_player.rotate_angle);
	g_player.x += x;
	g_player.y += y;
	render();
	render3d();
	render();
	generate_sprite();
	mlx_put_image_to_window(g_map.mlx_ptr, g_map.win_ptr, g_map.img_ptr, 0, 0);
	if (!g_is_screen_shot)
		my_clear();
	return (0);
}
