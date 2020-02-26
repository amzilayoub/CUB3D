/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_ceilling_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:15:26 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 15:39:15 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				skip_number_atoi(char *str)
{
	int i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
		i++;
	return (i);
}

t_hexa_color	read_hexa_file(char *line)
{
	int				i;
	t_hexa_color	hexa;

	valid_rgb_format(line);
	i = 2;
	hexa.red = ft_atoi(line + i);
	i += skip_number_atoi(line + i) + 1;
	hexa.green = ft_atoi(line + i);
	i += skip_number_atoi(line + i) + 1;
	hexa.blue = ft_atoi(line + i);
	return (hexa);
}
