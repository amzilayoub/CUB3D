/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:22:18 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/16 20:28:13 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void    treat_map(char *line)
{
    if (!g_map_list)
        g_map_list = ft_create_list(line);
    else
        ft_add_back(&g_map_list, line);
}

int     calc_map_width()
{
    int i;
    int c;

    i = -1;
    c = 0;
    while (g_map_list->line[++i])
    {
        if (g_map_list->line[i] == '1')
            c++;
    }
    return (c);
}


void    fill_map_row(int index, char *str)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while (str[++i])
    {
        if (str[i] >= '0' && str[i] <= '2')
        {
            g_world_map[index][++j] = str[i] - '0';
            if (!(str[i] == '2'))
                continue;
            g_sprites->x = j;
            g_sprites->y = index;
            printf("%d | %d\n", j, index);
        }
        else if (str[i] == 'S' || str[i] == 'N' || str[i] == 'E' || str[i] == 'W')
        {
            g_world_map[index][++j] = str[i];
            g_player.x = j;
            g_player.y = index;
            if (str[i] == 'N')
                g_player.rotate_angle = 1.5 * M_PI;
            else if (str[i] == 'E')
                g_player.rotate_angle = 0;
            else if (str[i] == 'S')
                g_player.rotate_angle = M_PI / 2;
            else if (str[i] == 'W')
                g_player.rotate_angle = M_PI;
        }
    }
}

void    fill_map()
{
    int i;
    t_map_from_file	*tmp;

    tmp = g_map_list;
    i = -1;
    g_map_width = calc_map_width();
    g_map_height = ft_list_size(g_map_list);
    if (!(g_world_map = (int**)malloc(sizeof(int*) * g_map_height)) ||
        !(g_sprites = (t_sprite*)malloc(sizeof(t_sprite))))
        return ;
    while (tmp)
    {
        if (!(g_world_map[++i] = (int*)malloc(sizeof(int) * g_map_width)))
            return ;
        fill_map_row(i, tmp->line);
        tmp = tmp->next;
    }
}

