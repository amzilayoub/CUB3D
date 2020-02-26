/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:46:24 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 22:45:43 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_texture_var(char *line, int tex)
{
	if (tex == NO)
		g_file_info.north = ft_split(line, ' ')[1];
	else if (tex == SO)
		g_file_info.south = ft_split(line, ' ')[1];
	else if (tex == WE)
		g_file_info.west = ft_split(line, ' ')[1];
	else if (tex == EA)
		g_file_info.east = ft_split(line, ' ')[1];
	else if (tex == S)
		g_file_info.sprite = ft_split(line, ' ')[1];
}
