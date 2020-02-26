/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:19:54 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 12:13:47 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_to_hexa(int r, int g, int b)
{
	return (r * pow(256, 2) + g * 256 + b);
}

float	calc_distance(float x, float y)
{
	float x_res;
	float y_res;

	x_res = g_player.x - x;
	y_res = g_player.y - y;
	return (sqrt(pow(x_res, 2) + pow(y_res, 2)));
}

void	my_clear(void)
{
	int i;
	int j;

	i = -1;
	while (++i < g_file_info.win_width)
	{
		j = -1;
		while (++j < g_file_info.win_height)
		{
			mlx_pixel_put_img(i, j, 0x000000);
		}
	}
}

void	fill_variables(void)
{
	g_all_rays = (t_ray*)my_malloc(sizeof(t_ray) * g_file_info.win_width);
	main_error_fun();
	error_and_exit();
	init_player();
	init_mlx_var();
	texture_data();
	generate_sprite();
	cast_ray();
}

int		main(int argc, char **argv)
{
	check_nb_arg(argc);
	g_file_path = argv[1];
	main_read_func();
	fill_variables();
	is_screen_shot(argc, argv);
	mlx_hook(g_map.win_ptr, 2, 1L << 0, event_handler, (void*)0);
	mlx_hook(g_map.win_ptr, 3, 1L << 1, key_release, (void*)0);
	mlx_hook(g_map.win_ptr, 17, 0L, destroy, (void*)0);
	mlx_loop_hook(g_map.mlx_ptr, draw, (void*)0);
	mlx_loop(g_map.mlx_ptr);
	return (0);
}
