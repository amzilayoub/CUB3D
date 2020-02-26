/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:10:39 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 11:32:56 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rgb	color_converter(int hex_value)
{
	t_rgb rgb_color;

	rgb_color.r = ((hex_value >> 16) & 0xFF);
	rgb_color.g = ((hex_value >> 8) & 0xFF);
	rgb_color.b = ((hex_value) & 0xFF);
	return (rgb_color);
}

void	init_bitmap_info(t_header_info *hf)
{
	int i;

	i = -1;
	hf->bitcount = 24;
	hf->width_in_bytes = ((g_file_info.win_width * hf->bitcount + 31) / 32) * 4;
	hf->imagesize = hf->width_in_bytes * g_file_info.win_height;
	hf->bi_size = 40;
	hf->bf_off_bits = 54;
	hf->filesize = 54 + hf->imagesize;
	hf->bi_planes = 1;
	while (++i < 54)
		hf->header[i] = 0;
}

void	init_header(t_header_info *hf)
{
	ft_memcpy(hf->header, "BM", 2);
	ft_memcpy(hf->header + 2, &hf->filesize, 4);
	ft_memcpy(hf->header + 10, &hf->bf_off_bits, 4);
	ft_memcpy(hf->header + 14, &hf->bi_size, 4);
	ft_memcpy(hf->header + 18, &g_file_info.win_width, 4);
	ft_memcpy(hf->header + 22, &g_file_info.win_height, 4);
	ft_memcpy(hf->header + 26, &hf->bi_planes, 2);
	ft_memcpy(hf->header + 28, &hf->bitcount, 2);
	ft_memcpy(hf->header + 34, &hf->imagesize, 4);
	hf->buf = my_malloc(hf->imagesize);
}

void	fill_the_buffer(t_header_info hf)
{
	int		row;
	int		col;
	t_rgb	my_rgb;

	row = -1;
	while (++row < g_file_info.win_height)
	{
		col = -1;
		while (++col < g_file_info.win_width)
		{
			my_rgb =
			color_converter(g_map.img_data[row * g_file_info.win_width + col]);
			hf.buf[(g_file_info.win_height - 1 - row)
			* hf.width_in_bytes + col * 3 + 0] = my_rgb.b;
			hf.buf[(g_file_info.win_height - 1 - row)
			* hf.width_in_bytes + col * 3 + 1] = my_rgb.g;
			hf.buf[(g_file_info.win_height - 1 - row)
			* hf.width_in_bytes + col * 3 + 2] = my_rgb.r;
		}
	}
}

void	create_bitmap(void)
{
	t_header_info	hf;
	int				fd;

	init_bitmap_info(&hf);
	init_header(&hf);
	fill_the_buffer(hf);
	fd = open("screen_shot.bmp", O_TRUNC | O_CREAT | O_WRONLY | O_APPEND);
	write(fd, hf.header, 54);
	write(fd, (char*)hf.buf, hf.imagesize);
	close(fd);
}
