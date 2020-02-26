/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memories.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:36:04 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/24 15:36:15 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			clear_memory(t_save_memories *node)
{
	if (node->next)
		clear_memory(node->next);
	free(node->memory);
	node->memory = NULL;
	free(node);
	node = NULL;
}
