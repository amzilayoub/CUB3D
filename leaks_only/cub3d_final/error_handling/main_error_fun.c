/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:38:37 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/22 15:05:24 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "error_handling.h"

void    init_error()
{
    g_error = 0;
    g_error_msg = NULL;
}

void    set_error(char *msg)
{
    g_error = 1;
    g_error_msg = msg;
}

void    check_if_error()
{
    if (g_error)
    {
        write(1, g_error_msg, ft_strlen(g_error_msg));
        exit(-1);
    }
}

void    main_error_fun()
{
    int i;

    i = -1;
    while (++i < 8)
        if (g_duplicate[i] != 1)
            set_error("Error\nDuplicate element in the info.cub !!\n");
    check_if_error();
    check_the_resolution();
    check_if_error();
    check_textures();
    check_if_error();
    check_the_map();
    check_if_error();
    check_the_rgb();
}
