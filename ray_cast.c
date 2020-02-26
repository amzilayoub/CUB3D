/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:01:52 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 12:09:29 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horz_cast(int facing_left, int facing_down, float ray_angle)
{
	g_y_horz_inter = (floor(g_player.y / g_box_size) * g_box_size) +
		(facing_down * g_box_size);
	g_x_horz_inter = (((g_y_horz_inter - g_player.y) / tan(ray_angle))
			+ g_player.x);
	g_y_horz_step = (facing_down) ? g_box_size : -g_box_size;
	g_x_horz_step = (g_box_size / tan(ray_angle));
	g_x_horz_step *= (facing_left && g_x_horz_step > 0) ? -1 : 1;
	g_x_horz_step *= (!facing_left && g_x_horz_step < 0) ? -1 : 1;
	while ((g_x_horz_inter >= 0 && g_x_horz_inter <=
				(g_map_width * g_box_size)) && (g_y_horz_inter >= 0 &&
					g_y_horz_inter < (g_map_height * g_box_size)))
	{
		if (is_hit_wall(g_x_horz_inter,
					g_y_horz_inter - ((!facing_down) ? 1 : 0)))
			break ;
		g_y_horz_inter += g_y_horz_step;
		g_x_horz_inter += g_x_horz_step;
	}
}

void	vert_cast(int facing_left, int facing_down, float ray_angle)
{
	g_x_vert_inter = (floor(g_player.x / g_box_size) * g_box_size) +
		(!facing_left * g_box_size);
	g_y_vert_inter = (((g_x_vert_inter - g_player.x) *
				tan(ray_angle)) + g_player.y);
	g_x_vert_step = (!facing_left) ? g_box_size : -g_box_size;
	g_y_vert_step = (g_box_size * tan(ray_angle));
	g_y_vert_step *= (facing_down && g_y_vert_step < 0) ? -1 : 1;
	g_y_vert_step *= (!facing_down && g_y_vert_step > 0) ? -1 : 1;
	while ((g_x_vert_inter >= 0 && g_x_vert_inter <=
				(g_map_width * g_box_size)) && (g_y_vert_inter >= 0 &&
					g_y_vert_inter < (g_map_height * g_box_size)))
	{
		if (is_hit_wall(g_x_vert_inter - ((facing_left) ? 1 : 0),
					g_y_vert_inter))
			break ;
		g_y_vert_inter += g_y_vert_step;
		g_x_vert_inter += g_x_vert_step;
	}
}

void	fill_rays_array(int facing_left, int facing_down,
		float ray_angle, int i)
{
	float		horz_ray;
	float		vert_ray;

	horz_ray = calc_distance(g_x_horz_inter, g_y_horz_inter);
	vert_ray = calc_distance(g_x_vert_inter, g_y_vert_inter);
	g_all_rays[i].hit_vertical = (horz_ray > vert_ray);
	g_all_rays[i].hit_x = (horz_ray > vert_ray) ?
							g_x_vert_inter : g_x_horz_inter;
	g_all_rays[i].hit_y = (horz_ray > vert_ray) ?
							g_y_vert_inter : g_y_horz_inter;
	g_all_rays[i].facing_down = facing_down;
	g_all_rays[i].facing_left = facing_left;
	horz_ray = (horz_ray > vert_ray) ? vert_ray : horz_ray;
	g_all_rays[i].ray_distance = horz_ray;
	g_all_rays[i].ray_angle = ray_angle;
}

void	cast_ray(void)
{
	float	ray_angle;
	int		i;
	int		facing_down;
	int		facing_left;

	i = -1;
	ray_angle = normalize_angle(g_player.rotate_angle - ((FOV_ANGLE) / 2));
	while (++i < g_num_rays)
	{
		if (ray_angle >= 2 * M_PI)
			ray_angle = normalize_angle(ray_angle);
		facing_down = ray_angle > 0 && ray_angle < M_PI;
		facing_left = ray_angle > (M_PI / 2) && ray_angle < (1.5 * M_PI);
		horz_cast(facing_left, facing_down, ray_angle);
		vert_cast(facing_left, facing_down, ray_angle);
		fill_rays_array(facing_left, facing_down, ray_angle, i);
		ray_angle += (FOV_ANGLE / g_num_rays);
	}
}
