/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_ceilling_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:15:26 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/15 17:51:40 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_hexa_color    read_hexa_file(char *line)
{
    int i;
    t_hexa_color hexa;

    i = 2;
    hexa.red = ft_atoi(line + i);
    i += skip_numbers(line + i) + 1;
    hexa.green = ft_atoi(line + i);
    i += skip_numbers(line + i) + 1;
    hexa.blue = ft_atoi(line + i);
    return (hexa);
}