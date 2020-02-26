/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_resolution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:38:37 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/24 15:26:12 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

void	check_the_resolution(void)
{
	if (g_file_info.win_width <= 0 || g_file_info.win_height <= 0)
		set_error("Error\nResolution Can't be null/negative !\n");
	else if (g_file_info.win_width * 2 > 5120 ||
			g_file_info.win_height * 2 > 2880)
	{
		if (g_file_info.win_width * 2 > 5120)
			g_file_info.win_width = (5120 / 2);
		if (g_file_info.win_height * 2 > 2880)
			g_file_info.win_height = (2880 / 2);
	}
}
