/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_floor_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:47:38 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/15 17:51:44 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void    treat_floor_color(char *line)
{
    int i;

    i = 2;
    g_file_info.floor_color.red = ft_atoi(line + i);
    i += skip_numbers(line + i) + 1;
    g_file_info.floor_color.green = ft_atoi(line + i);
    i += skip_numbers(line + i) + 1;
    g_file_info.floor_color.blue = ft_atoi(line + i);
}