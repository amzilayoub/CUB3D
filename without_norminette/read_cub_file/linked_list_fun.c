/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:57:46 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/23 19:23:13 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int                 ft_list_size(t_map_from_file *node)
{
    int i;

    i = 0;
    while (node)
    {
        i++;
        node = node->next;
    }
    return (i);
}

t_map_from_file     *ft_create_list(char *line)
{
    t_map_from_file *node;

    node = (t_map_from_file*)my_malloc(sizeof(t_map_from_file));
    node->line = line;
    node->next = NULL;
    return (node);
}

void    ft_add_back(t_map_from_file **node, char *line)
{
    if (!node)
        (*node) = ft_create_list(line);
    else if ((*node)->next)
        ft_add_back(&((*node)->next), line);
    else
        (*node)->next = ft_create_list(line);
}

t_save_memories     *ft_create_list_mem(void *memory)
{
    t_save_memories *node;

    node = (t_save_memories*)malloc(sizeof(t_save_memories));
    node->memory = memory;
    node->next = NULL;
    return (node);
}

void    ft_add_back_mem(t_save_memories **node, void *memory)
{
    if (!g_all_memories)
        g_all_memories = ft_create_list_mem(memory);
    else if ((*node)->next)
        ft_add_back_mem(&((*node)->next), memory);
    else
        (*node)->next = ft_create_list_mem(memory);
}

void    clear_memory(t_save_memories *node)
{
    if (node->next)
        clear_memory(node->next);
    free(node->memory);
    node->memory = NULL;
    free(node);
    node = NULL;
}