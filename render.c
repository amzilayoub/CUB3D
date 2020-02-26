/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:21:50 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 12:09:18 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(void)
{
	cast_ray();
}

void	render_floor(void)
{
	int color;
	int i;
	int j;

	color = rgb_to_hexa(g_file_info.floor_color.red,
			g_file_info.floor_color.green,
			g_file_info.floor_color.blue);
	i = g_file_info.win_height / 2;
	while (++i < g_file_info.win_height)
	{
		j = -1;
		while (++j < g_file_info.win_width)
			mlx_pixel_put_img(j, i, color);
	}
}

void	render_ceilling(void)
{
	int color;
	int i;
	int j;

	color = rgb_to_hexa(g_file_info.ceilling_color.red,
			g_file_info.ceilling_color.green,
			g_file_info.ceilling_color.blue);
	i = -1;
	while (++i < g_file_info.win_height / 2)
	{
		j = -1;
		while (++j < g_file_info.win_width)
			mlx_pixel_put_img(j, i, color);
	}
}

void	render3d(void)
{
	int		i;
	float	dis_proj_plan;
	float	wall_strip_height;
	float	dist;
	int		texture_off_x;

	i = -1;
	render_floor();
	render_ceilling();
	while (++i < g_num_rays)
	{
		dist = g_all_rays[i].ray_distance ? g_all_rays[i].ray_distance : 1;
		dis_proj_plan = (g_file_info.win_width / 2) / tan(FOV_ANGLE / 2);
		wall_strip_height = (g_box_size / (dist * cos(g_all_rays[i].ray_angle
						- g_player.rotate_angle))) * dis_proj_plan;
		texture_off_x = (g_all_rays[i].hit_vertical) ?
			g_all_rays[i].hit_y : g_all_rays[i].hit_x;
		texture_off_x %= (int)g_box_size;
		rect(i,
				(g_file_info.win_height / 2) - (wall_strip_height / 2),
				wall_strip_height, texture_off_x);
	}
}

void	rect(float x, float y, float height, int texture_off_x)
{
	int i;
	int texture_off_y;
	int texcolor;

	i = -1;
	while (++i < height)
	{
		texture_off_y = ((i - 1) * g_box_size) / height;
		if (!g_all_rays[(int)x].hit_vertical && !g_all_rays[(int)x].facing_down)
			texcolor = g_tex.data_img[0][(int)
				((g_box_size * texture_off_y) + texture_off_x)];
		else if (!g_all_rays[(int)x].hit_vertical &&
				g_all_rays[(int)x].facing_down)
			texcolor = g_tex.data_img[1][(int)
				((g_box_size * texture_off_y) + texture_off_x)];
		else if (g_all_rays[(int)x].hit_vertical &&
				g_all_rays[(int)x].facing_left)
			texcolor = g_tex.data_img[2][(int)
				((g_box_size * texture_off_y) + texture_off_x)];
		else if (g_all_rays[(int)x].hit_vertical &&
				!g_all_rays[(int)x].facing_left)
			texcolor = g_tex.data_img[3][(int)
				((g_box_size * texture_off_y) + texture_off_x)];
		mlx_pixel_put_img(x, y + i, texcolor);
	}
}
