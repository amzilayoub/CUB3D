/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_read_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 22:36:42 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/25 23:16:58 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_zero(int *t, int n)
{
	int i;

	i = -1;
	while (++i < n)
		t[i] = 0;
}

static void	prepare_for_the_map(char *line)
{
	if (g_total_data != 8)
	{
		set_error("Error\nError 404 Something wrong in the file '^_^!!\n");
		error_and_exit();
	}
	g_map_read_check[MAP_READED] = 1;
	if (line[0] == '\0' || line[0] == ' ')
		g_map_read_check[MAP_EMPTY_LINE] = 1;
	else if ((line[0] >= '0' && line[0] <= '9') &&
			g_map_read_check[MAP_EMPTY_LINE])
	{
		write(STDERR_FILENO, "Error\nEmpty line in the MAP !\n",
				ft_strlen("Error\nEmpty line in the MAP !\n"));
		clear_memory(g_all_memories);
		exit(-1);
	}
	if (line[0] >= '0' && line[0] <= '9')
		treat_map(line);
}

static void	find_right_func(char *line)
{
	int end_space;

	end_space = skip_spaces(line + 2);
	if (!ft_strncmp(line, "R", 1) && ++g_duplicate[0] && ++g_total_data)
		treat_resolution(line);
	else if (!ft_strncmp(line, "NO", 2) && ++g_duplicate[1] && ++g_total_data)
		fill_texture_var(line, NO);
	else if (!ft_strncmp(line, "SO", 2) && ++g_duplicate[2] && ++g_total_data)
		fill_texture_var(line, SO);
	else if (!ft_strncmp(line, "WE", 2) && ++g_duplicate[3] && ++g_total_data)
		fill_texture_var(line, WE);
	else if (!ft_strncmp(line, "EA", 2) && ++g_duplicate[4] && ++g_total_data)
		fill_texture_var(line, EA);
	else if (!ft_strncmp(line, "S", 1) && ++g_duplicate[5] && ++g_total_data)
		fill_texture_var(line, S);
	else if (!ft_strncmp(line, "F", 1) && ++g_duplicate[6] && ++g_total_data)
		g_file_info.floor_color = read_hexa_file(line);
	else if (!ft_strncmp(line, "C", 1) && ++g_duplicate[7] && ++g_total_data)
		g_file_info.ceilling_color = read_hexa_file(line);
	else if ((line[0] >= '0' && line[0] <= '9') ||
			(g_map_read_check[MAP_READED]))
		prepare_for_the_map(line);
}

void		check_extension_file(void)
{
	int		len;
	int		i;
	int		len_str;
	char	*str;

	i = -1;
	str = ".cub";
	len = ft_strlen(g_file_path) - 1;
	len_str = 3;
	while (++i < 4 && len >= 0 && len_str >= 0)
	{
		if (g_file_path[len] != str[len_str])
		{
			set_error("Error\nFile extension must end with .cub\n");
			write(1, g_error_msg, ft_strlen(g_error_msg));
			exit(-1);
		}
		len--;
		len_str--;
	}
}

void		main_read_func(void)
{
	int		fd;
	char	*line;

	g_player.nb_player = 0;
	g_total_data = 0;
	init_error();
	g_map_read_check[MAP_READED] = 0;
	g_map_read_check[MAP_EMPTY_LINE] = 0;
	check_extension_file();
	if ((fd = open(g_file_path, O_RDONLY)) < 0)
	{
		set_error("Error\nFile not exist !!\n");
		write(1, g_error_msg, ft_strlen(g_error_msg));
		exit(0);
	}
	set_zero(g_duplicate, 8);
	while (get_next_line(fd, &line))
	{
		find_right_func(line);
		ft_add_back_mem(&g_all_memories, line);
	}
	find_right_func(line);
	ft_add_back_mem(&g_all_memories, line);
	fill_map();
}
