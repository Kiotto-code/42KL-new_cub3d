/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:50:00 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/24 08:35:58 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// static void record_init(t_book *record)
// {
// 	record->map_table = (t_map *)malloc(sizeof(t_map));
// 	record->winsize = (t_coords *)malloc(sizeof(t_coords));
// }

static void record_init(t_book *record)
{
	*record = (t_book){0};
	// record->data = (t_data *)ft_calloc(sizeof(t_data));
	// record->game = (t_game *)ft_calloc(sizeof(t_game));
	record->winsize = (t_coords *)ft_calloc(sizeof(t_coords));
	record->map_table = (t_map *)ft_calloc(sizeof(t_map));
	// record->line_initial = (t_coords *)ft_calloc(sizeof(t_coords));
	// record->key = (t_keystate *)ft_calloc(sizeof(t_keystate));
}

// static void	cub_map_parse_helper_setter(t_game *g,
// 		int i, int j, float degree)
// {
// 	printf(BRIGHT_BLUE"i: %d, j: %d\n"RESET, i, j);
// 	// (g->map.arr)[i][j] = '1';
// 	// printf("i>map.arr[i][j]: %c", g->map.arr[i][j]);
// 	// fflush(stdout);
// 	// g->map.arr[i][j] = '0';
// 	g->player.map_pos_x = j;
// 	g->player.map_pos_y = i;
// 	g->player.pos.x = TILE_SIZE * j + TILE_SIZE / 2;
// 	g->player.pos.y = TILE_SIZE * i + TILE_SIZE / 2;
// 	g->player.width = PLAYER_WIDTH;
// 	g->player.height = PLAYER_HEIGHT;
// 	g->player.angle = degree;
// 	g->player.speed = PLAYER_SPEED;
// 	g->player.rot_speed = g->constants.player_rotation_speed;
// 	// (g->map.arr)[i][j] = '0';
// }

double player_pov_rad(int player)
{
	if (player == 'N')
		return (3 * M_PI / 2);
	else if (player == 'S')
		return ( M_PI / 2);
	else if (player == 'E')
		return ( 2 * M_PI);
	else if (player == 'W')
		return ( M_PI);
	else
		return ( -1 );
}	

static void record_player_struct(t_game *g, t_book *record)
{
	int i;
	int j;
	char pos;

	i = record->map_table->px;
	j = record->map_table->py;
	pos = record->map[j][i];

	printf("pos: %c\n", pos);
	// pause();

	g->player.map_pos_x = record->map_table->px;
	g->player.map_pos_y = record->map_table->py;
	g->player.pos.x = TILE_SIZE * j + TILE_SIZE / 2;
	g->player.pos.y = TILE_SIZE * i + TILE_SIZE / 2;
	g->player.width = PLAYER_WIDTH;
	g->player.height = PLAYER_HEIGHT;
	g->player.angle =  player_pov_rad(pos);
	if (g->player.angle == -1)
		ft_error("WRONG PLAYER POSITION", FAIL);
	g->player.speed = PLAYER_SPEED;
	g->player.rot_speed = g->constants.player_rotation_speed;
	// (g->map.arr)[i][j] = '0';

	
	ft_print_arr(record->map, "check: record.map");
	// pause();
}

void	init_g_constants(t_game *g)
{
	g->constants.frame_rate = 1000 / FPS;
	g->constants.half_win_width = WIN_W / 2;
	g->constants.half_win_height = WIN_H / 2;
	g->constants.fov = 60 * (M_PI / 180);
	g->constants.half_fov = g->constants.fov / 2;
	g->constants.screen_dist = WIN_W / 2 / tan(g->constants.half_fov);
	g->constants.num_rays = WIN_W;
	g->constants.half_num_rays = g->constants.num_rays / 2;
	g->constants.scale = WIN_W / g->constants.num_rays;
	g->constants.delta_angle = g->constants.fov / g->constants.num_rays;
	g->constants.player_rotation_speed = 90 * (M_PI / 180);
	g->constants.tau = 2 * M_PI;
}

void	cub_init_game_struct(t_game *g, char *filename)
{
	g->win.width = WIN_W;
	g->win.height = WIN_H;
	g->map.file.path = filename;
	// g->parsing.is_map = false;
	// g->parsing.map_initialized = false;
	// g->parsing.has_north = false;
	// g->parsing.has_south = false;
	// g->parsing.has_west = false;
	// g->parsing.has_east = false;
	// g->parsing.has_floor = false;
	// g->parsing.has_ceiling = false;
	g->paused = false;
	g->freeze = false;
	g->game_over = false;
	g->rays = (t_ray *) malloc(NUM_RAYS * sizeof(t_ray));
	if (!g->rays)
		ft_error("Failed to allocate rays", 1);
}

int main(int ac, char **av)
{
	t_data	data;
	t_book	record;
	t_game	g;

	// data.map = map_dup();

	if (ac != 2)
		ft_error("WRONG ARGUMENT: ./cub3d <map.cub>\n", 2);
	if (ft_strcmp(ft_strend(av[1], 4), ".cub") != 0)
		ft_error("WRONG FILE EXTENSION", 2);
	data = (t_data){0};
	record = (t_book){0};
	g = (t_game){0};
	cub_init_game_struct(&g, av[1]);
	init_g_constants(&g);
	record_init(&record);
	record.game= &g;
	record.data = &data;
	record.file = ft_strdup(av[1]);
	if (map_reading(&record) == FAIL)
		ft_error(RED"The map is not valid"RESET, FAIL);
	// ft_print_arr(record.map, "check: map:");
	// pause();
	if (file_data_recording(&record) == FAIL)
		ft_error(RED"file data recording failed"RESET, FAIL);
	// if (cub_init(&g))
	// 	ft_error("FAIL CUB_INIT", FAIL);

	// ft_print_arr(record.map, "check: record.map");
	
	g.map.arr = record.map;
	
	ft_print_arr(record.map, BRIGHT_CYAN"check2: g.map.arr"RESET);
	record_player_struct(&g, &record);

	ft_print_arr(record.map, BRIGHT_PURPLE"check3: data.map"RESET);
	init(&data, &record);
	(void)	ac;
	// (void)	av;
}