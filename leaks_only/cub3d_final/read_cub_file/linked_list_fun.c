/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:57:46 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/22 13:45:07 by aamzil           ###   ########.fr       */
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

    if (!(node = (t_map_from_file*)malloc(sizeof(t_map_from_file))))
        return (NULL);
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