/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 23:01:26 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/23 15:27:25 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    treat_resolution(char *line)
{
    int i;

    i = 2;
    g_file_info.win_width = ft_atoi(line + i);
    i += skip_numbers(line + i);
    g_file_info.win_height = ft_atoi(line + i + 1);
    g_file_info.win_height /= 2;
    g_file_info.win_width /= 2;
}