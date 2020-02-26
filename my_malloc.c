/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:51:00 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/24 22:20:22 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*my_malloc(size_t size)
{
	void *mem;

	if (!(mem = malloc(size)))
	{
		clear_memory(g_all_memories);
		write(1, "Error\nerror in malloc\n",
			ft_strlen("Error\nerror in malloc\n"));
		exit(-1);
	}
	if (!g_all_memories)
		g_all_memories = ft_create_list_mem(mem);
	else
		ft_add_back_mem(&g_all_memories, mem);
	return (mem);
}
