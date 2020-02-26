/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:56:41 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 12:03:22 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_data(void)
{
	int a;
	int b;

	g_tex.data_img = (int**)my_malloc(sizeof(int*) * 5);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.north, &a, &b);
	g_tex.data_img[0] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.south, &a, &b);
	g_tex.data_img[1] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.west, &a, &b);
	g_tex.data_img[2] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.east, &a, &b);
	g_tex.data_img[3] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.sprite,
			&a, &b);
	g_tex.data_img[4] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
}
