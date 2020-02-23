/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:10:39 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/23 15:13:53 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rgb color_converter (int hexValue)
{
    t_rgb rgbColor;

    rgbColor.r = ((hexValue >> 16) & 0xFF);
    rgbColor.g = ((hexValue >> 8) & 0xFF);
    rgbColor.b = ((hexValue) & 0xFF);
    return (rgbColor); 
}

void    init_bitmap_info(t_header_info *hf)
{
    hf->bitcount = 24;
    hf->width_in_bytes = ((g_file_info.win_width * hf->bitcount + 31) / 32) * 4;
    hf->imagesize = hf->width_in_bytes * g_file_info.win_height;
    hf->biSize = 40;
    hf->bfOffBits = 54;
    hf->filesize = 54 + hf->imagesize;
    hf->biPlanes = 1;
    int i = -1;
    while (++i < 54)
        hf->header[i] = 0;
}

void    init_header(t_header_info *hf)
{
    ft_memcpy(hf->header, "BM", 2);
    ft_memcpy(hf->header + 2 , &hf->filesize, 4);
    ft_memcpy(hf->header + 10, &hf->bfOffBits, 4);
    ft_memcpy(hf->header + 14, &hf->biSize, 4);
    ft_memcpy(hf->header + 18, &g_file_info.win_width, 4);
    ft_memcpy(hf->header + 22, &g_file_info.win_height, 4);
    ft_memcpy(hf->header + 26, &hf->biPlanes, 2);
    ft_memcpy(hf->header + 28, &hf->bitcount, 2);
    ft_memcpy(hf->header + 34, &hf->imagesize, 4);
    if (!(hf->buf = malloc(hf->imagesize)))
        return ;
}

void create_bitmap(void)
{
    t_header_info   hf;
    t_rgb           my_rgb;
    int             fd;

    init_bitmap_info(&hf);
    init_header(&hf);
    for(int row = 0 ; row <  g_file_info.win_height; row++)
    {
        for(int col = 0; col < g_file_info.win_width; col++)
        {
            my_rgb = color_converter(g_map.img_data[row * g_file_info.win_width + col]);
            hf.buf[(g_file_info.win_height - 1 - row ) * hf.width_in_bytes + col * 3 + 0] = my_rgb.b;
            hf.buf[(g_file_info.win_height - 1 - row ) * hf.width_in_bytes + col * 3 + 1] = my_rgb.g;
            hf.buf[(g_file_info.win_height - 1 - row ) * hf.width_in_bytes + col * 3 + 2] = my_rgb.r;
        }
    }
    fd = open("screen_shot.bmp", O_TRUNC | O_CREAT | O_WRONLY | O_APPEND);
    write(fd, hf.header, 54);
    write(fd, (char*)hf.buf, hf.imagesize);
    close(fd);
}