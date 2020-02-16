/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:36:42 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/15 18:10:06 by aamzil           ###   ########.fr       */
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

    end_space = 0;
    end_space += skip_numbers(line + 2);
    if (!ft_strncmp(line, "R", 1) && ++g_duplicate[0])
        treat_resolution(line);
    else if (!ft_strncmp(line, "NO", 2) && ++g_duplicate[1])
        g_file_info.north = ft_strdup(line + 2 + end_space + 1);
    else if (!ft_strncmp(line, "SO", 2) && ++g_duplicate[2])
        g_file_info.south = ft_strdup(line + 2 + end_space + 1);
    else if (!ft_strncmp(line, "WE", 2) && ++g_duplicate[3])
        g_file_info.west = ft_strdup(line + 2 + end_space + 1);
    else if (!ft_strncmp(line, "EA", 2) && ++g_duplicate[4])
        g_file_info.east = ft_strdup(line + 2 + end_space + 1);
    else if (!ft_strncmp(line, "S", 1) && ++g_duplicate[5])
        g_file_info.sprite = ft_strdup(line + 1 + end_space + 1);
    else if (!ft_strncmp(line, "F", 1) && ++g_duplicate[6])
        g_file_info.floor_color = read_hexa_file(line);
    else if (!ft_strncmp(line, "C", 1) && ++g_duplicate[7])
        g_file_info.ceilling_color = read_hexa_file(line);
    else if (line[0] >= '0' && line[0] <= '9')
        treat_map(line);
}

static void    check_the_info(char *line)
{
    char    *all_type_info;
    int     i;

    i = -1;
    all_type_info = "R/NO/SO/WE/EA/S/F/C";
    while (++i < (int)ft_strlen(all_type_info))
    {
        if (all_type_info[i] == '/')
            continue;
        else if (all_type_info[i] == line[0])
        {
            if (line[1] != ' ')
            {
                if (all_type_info[i + 1] == line[1])
                {
                    find_right_func(line);
                    break;
                }
            }
            else
            {
                find_right_func(line);
                break;
            }
        }
        else if (line[0] >= '0' && line[0] <= '9')
        {
            find_right_func(line);
            break;
        }
    }
}

void    main_read_func()
{
    int     fd;
    char *line;

    fd = open("info.cub", O_RDONLY);
    set_zero(g_duplicate, 8);
    while (get_next_line(fd, &line))
    {
        check_the_info(line);
        //i need to free here the line
    }
    check_the_info(line);
    fill_map();
}
