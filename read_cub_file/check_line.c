/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:07:33 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 22:49:54 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_line(char *line)
{
	int i;
	int nb_element;

	i = -1;
	nb_element = 0;
	while (line[++i])
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == '2' ||
					line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
					line[i] == 'W' || line[i] == ' '))
		{
			set_error("Error\nError in the MAP !!\n");
			write(1, g_error_msg, ft_strlen(g_error_msg));
			exit(-1);
		}
		else if (line[i] != ' ')
			nb_element++;
	}
	if (nb_element != g_map_width)
	{
		set_error("Error\nsome lines more/less than the map width!!\n");
		write(1, g_error_msg, ft_strlen(g_error_msg));
		exit(-1);
	}
}
