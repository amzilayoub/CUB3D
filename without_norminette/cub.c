/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <aamzil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:19:54 by aamzil            #+#    #+#             */
/*   Updated: 2020/02/23 23:31:25 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int					g_world_map[24][24] =
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };


int		destroy()
{
	//inned to free before
	clear_memory(g_all_memories);
	system("leaks a.out");
	exit(-1);
}

int		get_pixel_from_img(int x, int y)
{
	return (g_map.img_data[y * g_file_info.win_width + x]);
}

void	mlx_pixel_put_img(int x, int y, int color)
{
	if (x < 0 || x > g_file_info.win_width || y < 0 || y > g_file_info.win_height)
		return ;
	g_map.img_data[y * g_file_info.win_width + x] = color;
}

int		rgb_to_hexa(int r, int g, int b)
{
	return (r * pow(256, 2) + g * 256 + b);
}

void	init_player()
{
	g_box_size = 64;
	g_player.x *= g_box_size;
	g_player.y *= g_box_size;
	g_player.ray_long = 30;
	g_player.walk_speed = 15;
	g_player.walk_dir = 0;
	g_player.rotate_dir = 0;
	g_player.rotate_speed = 2;
	g_player.move_side = 0;
	g_x_horz_inter = 0;
	g_y_horz_inter = 0;
	g_num_rays = g_file_info.win_width;
}

float	normalize_angle(float angle)
{
	float degree_angle;

	degree_angle = (angle * 360) / (2 * M_PI);
	degree_angle = (int)degree_angle % (360);
	if (degree_angle < 0)
		degree_angle = degree_angle + (360);
	return (rad(degree_angle));
}

int     is_hit_wall(float x, float y)
{
	if (x < 0 || x > (g_map_width * g_box_size) || y < 0 || y > (g_map_height * g_box_size))
		return (1);
	x = floor(x / g_box_size);
	y = floor(y / g_box_size);
	return (g_world_map[(int)y][(int)x] == 1 ? 1 : 0);
}

void	one_box(int is_wall, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < g_box_size)
	{
		j = -1;
		while (++j < g_box_size)
			mlx_pixel_put_img(MIN_MAP * (i + x), MIN_MAP * (j + y), is_wall);
	}
}

void	render_line(float final_point, float angle)
{
	float x;
	float y;
	float r;

	r = -1;
	while (++r < final_point)
	{
		x = r * cos(angle);
		y = r * sin(angle);
		mlx_pixel_put_img(MIN_MAP * (g_player.x + x),MIN_MAP * (g_player.y + y), 0xf7b731);
	}
}

float		calc_distance(float x, float y)
{
	float x_res;
	float y_res;

	x_res = g_player.x - x;
	y_res = g_player.y - y;
	return (sqrt(pow(x_res, 2) + pow(y_res, 2)));
}

void    cast_ray()
{
	float   ray_angle;
	int     i;
	int     facing_down;
	int     facing_left;
	float		horz_ray;
	float		vert_ray;
	i = -1;
	ray_angle = normalize_angle(g_player.rotate_angle - ((FOV_ANGLE) / 2));
	while (++i < g_num_rays)
	{
		if (ray_angle >= 2 * M_PI)
			ray_angle = normalize_angle(ray_angle);
		facing_down = ray_angle > 0 && ray_angle < M_PI;
		facing_left = ray_angle > (M_PI / 2) && ray_angle < (1.5 * M_PI);
		
		g_y_horz_inter = (floor(g_player.y / g_box_size) * g_box_size) + (facing_down * g_box_size);
		g_x_horz_inter = (((g_y_horz_inter - g_player.y) / tan(ray_angle)) + g_player.x);
		g_y_horz_step = (facing_down) ? g_box_size : -g_box_size;
		g_x_horz_step = (g_box_size / tan(ray_angle));
		g_x_horz_step *= (facing_left && g_x_horz_step > 0) ? -1 : 1;
		g_x_horz_step *= (!facing_left && g_x_horz_step < 0) ? -1 : 1;
		while ((g_x_horz_inter >= 0 && g_x_horz_inter <= (g_map_width * g_box_size)) &&
				(g_y_horz_inter >= 0 && g_y_horz_inter < (g_map_height * g_box_size)))
		{
			if (is_hit_wall(g_x_horz_inter, g_y_horz_inter - ((!facing_down) ? 1 : 0)))
				break;
			g_y_horz_inter += g_y_horz_step;
			g_x_horz_inter += g_x_horz_step;
		}

		g_x_vert_inter = (floor(g_player.x / g_box_size) * g_box_size) + (!facing_left * g_box_size);
		g_y_vert_inter = (((g_x_vert_inter - g_player.x) * tan(ray_angle)) + g_player.y);
		g_x_vert_step = (!facing_left) ? g_box_size : -g_box_size;
		g_y_vert_step = (g_box_size * tan(ray_angle));
		g_y_vert_step *= (facing_down && g_y_vert_step < 0) ? -1 : 1;
		g_y_vert_step *= (!facing_down && g_y_vert_step > 0) ? -1 : 1;
		while ((g_x_vert_inter >= 0 && g_x_vert_inter <= (g_map_width * g_box_size)) &&
				(g_y_vert_inter >= 0 && g_y_vert_inter < (g_map_height * g_box_size)))
		{
			if (is_hit_wall(g_x_vert_inter - ((facing_left) ? 1 : 0), g_y_vert_inter))
				break;
			g_y_vert_inter += g_y_vert_step;
			g_x_vert_inter += g_x_vert_step;
		}
		horz_ray = calc_distance(g_x_horz_inter, g_y_horz_inter);
		vert_ray = calc_distance(g_x_vert_inter, g_y_vert_inter);
		all_rays[i].hit_vertical = (horz_ray > vert_ray);
		all_rays[i].hit_x = (horz_ray > vert_ray) ? g_x_vert_inter : g_x_horz_inter;
		all_rays[i].hit_y = (horz_ray > vert_ray) ? g_y_vert_inter : g_y_horz_inter;
		all_rays[i].facing_down = facing_down;
		all_rays[i].facing_left = facing_left;
		horz_ray = (horz_ray > vert_ray) ? vert_ray : horz_ray;
		all_rays[i].ray_distance = horz_ray;
		all_rays[i].ray_angle = ray_angle;
		render_line(horz_ray, ray_angle);
		ray_angle += (FOV_ANGLE / g_num_rays);
	}
}
void	render_player()
{
	float angle;

	angle = 361;
	while (--angle >= 0)
		render_line(5, rad(angle));
}

void	render_map()
{
	int i;
	int j;
	int is_wall;

	i = -1;
	while (++i < g_map_height)
	{
		j = -1;
		while (++j < g_map_width)
		{
			is_wall = (g_world_map[i][j] == 1) ? 0xd1d8e0 : 0x4b7bec;
			one_box(is_wall, j * g_box_size, i * g_box_size);
		}
	}
}

int		key_release(int key)
{
	if (key == 123 || key == 124)
		g_player.rotate_dir = 0;
	if (key == 1 || key == 13)
		g_player.walk_dir = 0;
	if (key == 2 || key == 0)
		g_player.move_side = 0;
	return (0);
}

int		event_handler(int key)
{
	// LEFT
	if (key == 123)
		g_player.rotate_dir = -1;
	// RIGHT
	else if (key == 124)
		g_player.rotate_dir = 1;
	// BOTTOM
	else if (key == 1)
		g_player.walk_dir = -1;
	// TOP
	else if (key == 13)
		g_player.walk_dir = 1;
	// Move Right
	else if (key == 2)
		g_player.move_side = 1;
	// Move left
	else if (key == 0)
		g_player.move_side = -1;
	else if (key == 53)
		destroy();
	printf("%d\n", key);
	return (0);
}

void	my_clear()
{
	int i;
	int j;

	i = -1;
	while (++i < g_file_info.win_width)
	{
		j = -1;
		while (++j < g_file_info.win_height)
		{
			mlx_pixel_put_img(i,j,0x000000);
		}
	}
}

void	render()
{
	render_map();
	render_player();
	cast_ray();
}

int		draw()
{
	float steps;
	float x;
	float y;

	g_player.rotate_angle += rad(g_player.rotate_speed * g_player.rotate_dir);
	steps = g_player.walk_speed * (float)g_player.walk_dir;
	x = cos(g_player.rotate_angle) * steps;
	y = sin(g_player.rotate_angle) * steps;
	x += (g_player.move_side * g_player.walk_speed) * cos(rad(90) + g_player.rotate_angle);
	y += (g_player.move_side * g_player.walk_speed) * sin(rad(90) + g_player.rotate_angle);
	g_player.x += x;
	g_player.y += y;
	render();
	render3d();
	render();
	generate_sprite();
	mlx_put_image_to_window(g_map.mlx_ptr, g_map.win_ptr, g_map.img_ptr, 0, 0);
	if (!is_screen_shot)
		my_clear();
	return (0);
}


void	rect(float x, float y, float height, int texture_off_x)
{
	int i;
	int texture_off_y;
	int texcolor;

	i = -1;
	while (++i < height)
	{
		texture_off_y = ((i - 1) * g_box_size) / height;
		if (!all_rays[(int)x].hit_vertical && !all_rays[(int)x].facing_down)
			texcolor = g_tex.data_img[0][(int)((g_box_size * texture_off_y) + texture_off_x)];
		else if (!all_rays[(int)x].hit_vertical && all_rays[(int)x].facing_down)
			texcolor = g_tex.data_img[1][(int)((g_box_size * texture_off_y) + texture_off_x)];
		else if (all_rays[(int)x].hit_vertical && all_rays[(int)x].facing_left)
			texcolor = g_tex.data_img[2][(int)((g_box_size * texture_off_y) + texture_off_x)];
		else if (all_rays[(int)x].hit_vertical && !all_rays[(int)x].facing_left)
			texcolor = g_tex.data_img[3][(int)((g_box_size * texture_off_y) + texture_off_x)];
		mlx_pixel_put_img(x, y + i, texcolor);
	}
}

void	render_floor()
{
	int color;
	int i;
	int j;

	color = rgb_to_hexa(g_file_info.floor_color.red,
						g_file_info.floor_color.green,
						g_file_info.floor_color.blue);
	i = g_file_info.win_height / 2;
	while (++i < g_file_info.win_height)
	{
		j = -1;
		while (++j < g_file_info.win_width)
			mlx_pixel_put_img(j, i, color);
	}
}

void	render_ceilling()
{
	int color;
	int i;
	int j;

	color = rgb_to_hexa(g_file_info.ceilling_color.red,
						g_file_info.ceilling_color.green,
						g_file_info.ceilling_color.blue);
	i = -1;
	while (++i < g_file_info.win_height / 2)
	{
		j = -1;
		while (++j < g_file_info.win_width)
			mlx_pixel_put_img(j, i, color);
	}
}

void	render3d()
{
	int		i;
	float	dis_proj_plan;
	float	wall_strip_height;
	float	dist;
	int		texture_off_x;

	i = -1;
	render_floor();
	render_ceilling();
	while (++i < g_num_rays)
	{
		dist = all_rays[i].ray_distance ? all_rays[i].ray_distance : 1;
		dis_proj_plan = (g_file_info.win_width / 2) / tan(FOV_ANGLE / 2);
		wall_strip_height = (g_box_size / (dist * cos(all_rays[i].ray_angle - g_player.rotate_angle))) * dis_proj_plan;
		texture_off_x = (all_rays[i].hit_vertical) ? all_rays[i].hit_y : all_rays[i].hit_x;
		texture_off_x %= (int)g_box_size;
		rect(i, (g_file_info.win_height / 2) - (wall_strip_height / 2), wall_strip_height, texture_off_x);
	}
}

void	texture_data()
{
	int a;
	int b;
	g_tex.data_img = (int**)my_malloc(sizeof(int*) * 5);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.north,&a, &b);
	g_tex.data_img[0] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.south,&a, &b);
	g_tex.data_img[1] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.west,&a, &b);
	g_tex.data_img[2] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.east,&a, &b);
	g_tex.data_img[3] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
	g_tex.img = mlx_xpm_file_to_image(g_map.mlx_ptr, g_file_info.sprite,&a, &b);
	g_tex.data_img[4] = (int*)mlx_get_data_addr(g_tex.img, &a, &a, &a);
}

int		is_save_param(char *str)
{
	char *save;

	save = "--save";
	if ((ft_strlen(str) != ft_strlen(save)) || ft_strncmp(save, str, ft_strlen(save)))
	{
		set_error("Error\nError in the argument 3 !!\n");
		write(1, g_error_msg, ft_strlen(g_error_msg));
		exit(-1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int useless;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n Error in the number of argiments\n", ft_strlen("Error\n Error in the number of argiments\n"));
		exit(-1);
	}
	g_file_path = argv[1];
	g_nb_sprites = 0;
	is_screen_shot = 0;
	main_read_func();
	all_rays = (t_ray*)malloc(sizeof(t_ray) * g_file_info.win_width);
	// g_file_info.win_width = 2000;
    // g_file_info.win_height = 1000;
    // g_file_info.north = "./textures/EA.xpm";
    // g_file_info.south = "./textures/EA.xpm";
    // g_file_info.west = "./textures/EA.xpm";
    // g_file_info.east = "./textures/EA.xpm";
    // g_file_info.sprite = "./textures/EA.xpm";
    // g_file_info.floor_color.red = 200;
    // g_file_info.floor_color.green = 0;
    // g_file_info.floor_color.blue = 0;
    // g_file_info.ceilling_color.red = 200;
    // g_file_info.ceilling_color.green = 0;
    // g_file_info.ceilling_color.blue = 0;
	// g_map_width = 24;
	// g_map_height = 24;
	main_error_fun();
	if (g_error)
	{
		write(1, g_error_msg, ft_strlen(g_error_msg));
		clear_memory(g_all_memories);
		return (0);
	}
	/*
	int i;
	int j;

	i = -1;

	while (++i < g_map_width)
	{
		j = -1;
		while (++j < g_map_height)
		{
			printf("%d ", g_world_map[j][i]);
		}
		printf("\n");
	}
	*/
	init_player();
	g_map.mlx_ptr = mlx_init();
	g_map.win_ptr = mlx_new_window(g_map.mlx_ptr, g_file_info.win_width, g_file_info.win_height, "CUB3D");
	g_map.img_ptr = mlx_new_image(g_map.mlx_ptr, g_file_info.win_width, g_file_info.win_height);
	g_map.img_data = (int *)mlx_get_data_addr(g_map.img_ptr, &useless, &useless, &useless);
	texture_data();
	generate_sprite();
	render_map();
	render_player();
	cast_ray();
	if ((argc == 3) && is_save_param(argv[2]))
	{
		is_screen_shot = 1;
		draw();
		create_bitmap();
		clear_memory(g_all_memories);
		return 0;
	}
	//printf("LIST = %s\n", g_map_list->line);
	/*
	printf("SIZE = %d\n", ft_list_size(g_map_list));
	t_map_from_file *test;
	test = g_map_list;
	while (test)
	{
		printf("LIST = %s\n", test->line);
		test = test->next;
	}
	*/
	mlx_hook(g_map.win_ptr, 2, 1L<<0, event_handler, (void*)0);
	mlx_hook(g_map.win_ptr, 3, 1L<<1, key_release, (void*)0);
	mlx_hook(g_map.win_ptr, 17, 0L, destroy, (void*)0);
	mlx_loop_hook(g_map.mlx_ptr, draw, (void*)0);
	mlx_loop(g_map.mlx_ptr);
	return (0);
}
