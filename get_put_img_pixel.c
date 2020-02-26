/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put_img_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:53:55 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/24 22:15:13 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_pixel_from_img(int x, int y)
{
	return (g_map.img_data[y * g_file_info.win_width + x]);
}

void	mlx_pixel_put_img(int x, int y, int color)
{
	if (x < 0 || x > g_file_info.win_width ||
		y < 0 || y > g_file_info.win_height)
		return ;
	g_map.img_data[y * g_file_info.win_width + x] = color;
}
