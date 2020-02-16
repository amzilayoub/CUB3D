/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:24:28 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/16 20:33:25 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    render_sprite(float x_offset, float y_offset, t_sprite *sprite)
{
    int i;
    int j;
    int color;

    i = -1;
    j = -1;
    while (++i < sprite->size)
    {
        if (x_offset + i < 0 || x_offset + i > g_file_info.win_width)
            continue;

            // printf("lll\n");
        j = -1;
        while (++j < sprite->size)
        {    //printf("%f | %d\n", sprite->size, j);
            
             if (y_offset + j < 0 || y_offset + j > g_file_info.win_height)
                 continue;
            color = g_tex.data_img[4][(int)(64 * (j * 64 / sprite->size) + (i * 64 / sprite->size))];
            // if (color)
                mlx_pixel_put_img((x_offset + i), (y_offset + j), color);
                // printf("done %d, %d\n", i,j);
        }
    }
}

void    treat_sprites(t_sprite *sprite)
{
    float x_offset;
    float y_offset;
    float angle;
    if (g_player.rotate_angle >= 2 * M_PI)
        g_player.rotate_angle = normalize_angle(g_player.rotate_angle);
    sprite->dist = calc_distance(sprite->x * g_box_size,
                                    sprite->y * g_box_size);
    sprite->angle = atan2(-g_player.y + (sprite->y * g_box_size),
                            -g_player.x + (sprite->x * g_box_size));
    while (sprite->angle - g_player.rotate_angle > M_PI)
		sprite->angle -= 2 * M_PI;
	while (sprite->angle - g_player.rotate_angle < -M_PI)
		sprite->angle += 2 * M_PI;
    //sprite->angle =  fmod(sprite->angle, 2 * M_PI);
	//if (sprite->angle < 0)
		//sprite->angle += 2 * M_PI;
    // sprite->angle = normalize_angle(sprite->angle);
    if (g_file_info.win_width >= g_file_info.win_height)
        sprite->size = (g_file_info.win_width / sprite->dist * 64);
    else
        sprite->size = (g_file_info.win_height / sprite->dist * 64);
    x_offset = (sprite->angle - g_player.rotate_angle) * g_file_info.win_width / (FOV_ANGLE) + (g_file_info.win_width / 2 - sprite->size / 2);
    y_offset = g_file_info.win_height / 2 - sprite->size / 2;
    render_sprite(x_offset, y_offset, sprite);
}