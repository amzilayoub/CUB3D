/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:36:42 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/23 15:06:42 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    set_zero(int *t, int n)
{
    int i;

    i = -1;
    while (++i < n)
        t[i] = 0;
}

static void    find_right_func(char *line)
{
    int end_space;

    end_space = skip_spaces(line + 2);
    if (!ft_strncmp(line, "R", 1) && ++g_duplicate[0])
        treat_resolution(line);
    else if (!ft_strncmp(line, "NO", 2) && ++g_duplicate[1])
        g_file_info.north = ft_strdup(line + 2 + end_space);
    else if (!ft_strncmp(line, "SO", 2) && ++g_duplicate[2])
        g_file_info.south = ft_strdup(line + 2 + end_space);
    else if (!ft_strncmp(line, "WE", 2) && ++g_duplicate[3])
        g_file_info.west = ft_strdup(line + 2 + end_space);
    else if (!ft_strncmp(line, "EA", 2) && ++g_duplicate[4])
        g_file_info.east = ft_strdup(line + 2 + end_space);
    else if (!ft_strncmp(line, "S", 1) && ++g_duplicate[5])
        g_file_info.sprite = ft_strdup(line + 1 + skip_spaces(line + 1));
    else if (!ft_strncmp(line, "F", 1) && ++g_duplicate[6])
        g_file_info.floor_color = read_hexa_file(line);
    else if (!ft_strncmp(line, "C", 1) && ++g_duplicate[7])
        g_file_info.ceilling_color = read_hexa_file(line);
    else if ((line[0] >= '0' && line[0] <= '9') || (g_map_read_check[MAP_READED]))
    {
        g_map_read_check[MAP_READED] = 1;
        if (line[0] == '\0' || line[0] == ' ')
            g_map_read_check[MAP_EMPTY_LINE] = 1;
        else if ((line[0] >= '0' && line[0] <= '9') && g_map_read_check[MAP_EMPTY_LINE])
        {
            write(STDERR_FILENO,"Error\nEmpty line in the MAP !\n", ft_strlen("Error\nEmpty line in the MAP !\n"));
            exit(-1);
        }
        if (line[0] >= '0' && line[0] <= '9')
            treat_map(line);
    }
    //printf("%s\n", g_file_info.sprite );
}

void    main_read_func()
{
    int     fd;
    char *line;

    init_error();
    g_map_read_check[MAP_READED] = 0;
    g_map_read_check[MAP_EMPTY_LINE] = 0;
    fd = open("info.cub", O_RDONLY);
    set_zero(g_duplicate, 8);
    while (get_next_line(fd, &line))
    {
        //printf("%s\n", line);
        find_right_func(line);
        //i need to free here the line
    }
    find_right_func(line);
    //get_next_line(fd, &line);
    
    //find_right_func(line);
    fill_map();
}
