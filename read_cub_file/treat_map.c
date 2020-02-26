/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:22:18 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 22:51:56 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	treat_map(char *line)
{
	if (!g_map_list)
		g_map_list = ft_create_list(line);
	else
		ft_add_back(&g_map_list, line);
}

int		calc_map_width(void)
{
	int i;
	int c;

	i = -1;
	c = 0;
	if (!g_map_list)
	{
		set_error("Error\ni got you bitch\nEmpty File or empty map !!\n");
		error_and_exit();
	}
	while (g_map_list->line[++i])
	{
		if (g_map_list->line[i] == '1')
			c++;
	}
	return (c);
}

void	fill_map_row_helper(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		g_player.nb_player++;
	if (c == 'N')
		g_player.rotate_angle = 1.5 * M_PI;
	else if (c == 'E')
		g_player.rotate_angle = 0;
	else if (c == 'S')
		g_player.rotate_angle = M_PI / 2;
	else if (c == 'W')
		g_player.rotate_angle = M_PI;
}

void	fill_map_row(int index, char *str)
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
			g_nb_sprites++;
		}
		else if (str[i] == 'S' || str[i] == 'N'
				|| str[i] == 'E' || str[i] == 'W')
		{
			g_world_map[index][++j] = str[i];
			g_player.x = j;
			g_player.y = index;
			fill_map_row_helper(str[i]);
		}
	}
}

void	fill_map(void)
{
	int				i;
	t_map_from_file	*tmp;

	tmp = g_map_list;
	i = -1;
	g_map_width = calc_map_width();
	g_map_height = ft_list_size(g_map_list);
	g_world_map = (int**)my_malloc(sizeof(int*) * g_map_height);
	while (tmp)
	{
		check_line(tmp->line);
		g_world_map[++i] = (int*)my_malloc(sizeof(int) * g_map_width);
		fill_map_row(i, tmp->line);
		tmp = tmp->next;
	}
}
