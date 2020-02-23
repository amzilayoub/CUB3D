/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:13:53 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/22 19:38:05 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

void    check_textures()
{
    int fd;

    if ((fd = open(g_file_info.north ,O_RDONLY)) < 0)
        set_error("Error\nNorth Texture not exists !\n");
    else if ((fd = open(g_file_info.south ,O_RDONLY)) < 0)
        set_error("Error\nSouth Texture not exists !\n");
    else if ((fd = open(g_file_info.west ,O_RDONLY)) < 0)
        set_error("Error\nWest Texture not exists !\n");
    else if ((fd = open(g_file_info.east ,O_RDONLY)) < 0)
        set_error("Error\nEast Texture not exists !\n");
    else if ((fd = open(g_file_info.sprite ,O_RDONLY)) < 0)
        set_error("Error\nSprite Texture not exists !\n");
    if (fd > 0)
        close(fd);
}