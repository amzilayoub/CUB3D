/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:38:37 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/15 17:54:10 by aamzil           ###   ########.fr       */
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

void    main_error_fun()
{
    int i;

    init_error();
    i = -1;
    while (++i < 8)
        if (g_duplicate[i] != 1)
            set_error("Duplicate element in the info.cub !!\n");
    if (g_error)
        return ;
    check_the_map();
    check_the_rgb();
    check_the_resolution();
}
