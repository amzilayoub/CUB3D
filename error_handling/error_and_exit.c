/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:47:18 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 11:13:50 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"

void	check_nb_arg(int nb)
{
	if (nb < 2 || nb > 3)
	{
		write(1, "Error\n Error in the number of argiments\n",
				ft_strlen("Error\n Error in the number of argiments\n"));
		exit(-1);
	}
	g_nb_sprites = 0;
	g_is_screen_shot = 0;
}

void	error_and_exit(void)
{
	if (g_error)
	{
		write(1, g_error_msg, ft_strlen(g_error_msg));
		clear_memory(g_all_memories);
		exit(-1);
	}
}
