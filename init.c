/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:59:21 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 15:25:01 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_var(void)
{
	int useless;

	g_map.mlx_ptr = mlx_init();
	g_map.win_ptr = mlx_new_window(
									g_map.mlx_ptr,
									g_file_info.win_width,
									g_file_info.win_height,
									"CUB3D");
	g_map.img_ptr = mlx_new_image(
									g_map.mlx_ptr,
									g_file_info.win_width,
									g_file_info.win_height);
	g_map.img_data = (int *)mlx_get_data_addr(
												g_map.img_ptr,
												&useless,
												&useless,
												&useless);
}

void	init_player(void)
{
	g_box_size = 64;
	g_player.x *= g_box_size;
	g_player.y *= g_box_size;
	g_player.ray_long = 30;
	g_player.walk_speed = 15;
	g_player.walk_dir = 0;
	g_player.rotate_dir = 0;
	g_player.rotate_speed = 2;
	g_player.move_side = 0;
	g_x_horz_inter = 0;
	g_y_horz_inter = 0;
	g_num_rays = g_file_info.win_width;
}
