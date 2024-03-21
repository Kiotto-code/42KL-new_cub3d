/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:50:00 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/21 16:46:03 by yichan           ###   ########.fr       */
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

static void	cub_map_parse_helper_setter(t_game *g,
		int i, int j, float degree)
{
	printf(BRIGHT_BLUE"i: %d, j: %d\n"RESET, i, j);
	// (g->map.arr)[i][j] = '1';
	// printf("i>map.arr[i][j]: %c", g->map.arr[i][j]);
	// fflush(stdout);
	// g->map.arr[i][j] = '0';
	g->player.map_pos_x = j;
	g->player.map_pos_y = i;
	g->player.pos.x = TILE_SIZE * j + TILE_SIZE / 2;
	g->player.pos.y = TILE_SIZE * i + TILE_SIZE / 2;
	g->player.width = PLAYER_WIDTH;
	g->player.height = PLAYER_HEIGHT;
	g->player.angle = degree;
	g->player.speed = PLAYER_SPEED;
	g->player.rot_speed = g->constants.player_rotation_speed;
	// (g->map.arr)[i][j] = '0';
}

static void record_player_struct(t_game *g, t_book *record)
{
	int i;
	int j;

	i = 0;
	// ft_print_arr(record->map, "check: record.map");
	// pause();
	while (record->map[i])
	{
		j = 0;
		while (record->map[i][j])
		{
			if (ft_strchr("NSWE", record->map[i][j]))
				break;
			j++;
		}
		if (ft_strchr("NSWE", record->map[i][j]))
			break;
		i++;
	}
	if (record->map[i] == NULL)
		ft_error("NO PLAYER FOUND", FAIL);
	// ft_print_arr(record->map, "check: record.map");
	// pause();
	cub_map_parse_helper_setter(g, i, j, -1);
	ft_print_arr(record->map, "check: record.map");
	// pause();
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

	// ft_print_arr(record.map, "check: record.map");
	
	g.map.arr = record.map;
	
	ft_print_arr(record.map, BRIGHT_CYAN"check2: g.map.arr"RESET);
	record_player_struct(&g, &record);

	ft_print_arr(record.map, BRIGHT_PURPLE"check3: data.map"RESET);
	init(&data, &record);
	(void)	ac;
	// (void)	av;
}