/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:39:26 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 22:53:21 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		init_table(int *nb, int *i)
{
	nb[0] = 0;
	nb[1] = 0;
	nb[2] = 0;
	*i = 0;
}

static void		helper_function(int coma, int *nb)
{
	if (coma > 3)
		set_error("Error\nError in the RGB Color !!\n");
	else if (!nb[0] || !nb[1] || !nb[2])
		set_error("Error\nError in the RGB Color !!\n");
}

void			valid_rgb_format(char *line)
{
	int i;
	int nb[3];
	int coma;

	coma = 0;
	init_table(nb, &i);
	while (line[++i])
	{
		if ((line[i] == ',') || (line[i] >= '0' && line[i] <= '9' &&
					coma < 3) || line[i] == ' ')
		{
			if (line[i] == ',')
				coma++;
			else if (line[i] >= '0' && line[i] <= '9' && coma < 3)
				nb[coma]++;
		}
		else
		{
			set_error("Error\nError in the RGB format\n");
			write(1, g_error_msg, ft_strlen(g_error_msg));
			exit(-1);
		}
	}
	helper_function(coma, nb);
}
