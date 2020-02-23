/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:38:31 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/22 14:24:09 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "error_handling.h"

int     check_valide_player_map(int i)
{
    if (i == 'N' || i == 'E' || i == 'S' || i == 'W')
        return (1);
    return (0);
}

void     check_the_map()
{
    int i;
    int j;
    int sprite;
    int player;

    i = -1;
    sprite = 0;
    player = 0;
    while (++i < g_map_height && !g_error)
    {
        j = -1;
        while (++j < g_map_width && !g_error)
        {
            if (!((g_world_map[i][j] >= 0 && g_world_map[i][j] <= 2) || check_valide_player_map(g_world_map[i][j])))
                set_error("Error in  the MAP !!\n");
            if (((i == 0 || i == g_map_height - 1) && g_world_map[i][j] != 1)
            || ((j == 0 || j == g_map_width - 1) && g_world_map[i][j] != 1))
            {
                printf("%d | %d\n", g_map_height, g_map_width);
                set_error("Error in  the MAP !!\n");   
            }
            else if (g_world_map[i][j] == 2)
                sprite = 1;
        }
    }
    if (!sprite)
        set_error("Error in  the MAP !!\n");
}