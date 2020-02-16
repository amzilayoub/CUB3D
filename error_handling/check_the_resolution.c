/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_resolution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:38:37 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/15 17:50:41 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

void    check_the_resolution()
{
    if (g_file_info.win_width <= 0 || g_file_info.win_height <= 0)
        set_error("Resolution Can't be null/negative !\n");
}