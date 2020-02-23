/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:24:01 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/15 17:50:46 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_the_rgb()
{
    if (g_file_info.floor_color.red > 255 || g_file_info.floor_color.red < 0
    || g_file_info.floor_color.green > 255 || g_file_info.floor_color.green < 0
    || g_file_info.floor_color.blue > 255 || g_file_info.floor_color.blue < 0)
        set_error("Error in the RGB color\n");
    else if (g_file_info.ceilling_color.red > 255 || g_file_info.ceilling_color.red < 0
    || g_file_info.ceilling_color.green > 255 || g_file_info.ceilling_color.green < 0
    || g_file_info.ceilling_color.blue > 255 || g_file_info.ceilling_color.blue < 0)
        set_error("Error in the RGB color\n");
}