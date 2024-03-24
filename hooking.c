/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:27:32 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/24 08:50:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

typedef struct timespec	t_timespec;

unsigned long long	current_time_ms(void)
{
	t_timespec	now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	return (now.tv_sec * 1000 + now.tv_nsec / 1000000);
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		printf("game ended\n");
		exit (0);
	}
	if (keycode == KEY_W)
		data->player->walk_direction = -1;
	else if (keycode == KEY_S)
		data->player->walk_direction = 1;
	else if (keycode == KEY_A)
		data->player->turn_direction = -1;
	else if (keycode == KEY_D)
		data->player->turn_direction = 1;
	else if (keycode == ARROW_LEFT)
		data->player->rotation_direction = -1;
	else if (keycode == ARROW_RIGHT)
		data->player->rotation_direction = 1;
	else if (keycode == SPACE)
		data->keystate->space = 1;
	return (0);
}

int	keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->player->walk_direction = 0;
	else if (keycode == KEY_S)
		data->player->walk_direction = 0;
	else if (keycode == KEY_A)
		data->player->turn_direction = 0;
	else if (keycode == KEY_D)
		data->player->turn_direction = 0;
	else if (keycode == ARROW_LEFT)
		data->player->rotation_direction = 0;
	else if (keycode == ARROW_RIGHT)
		data->player->rotation_direction = 0;
	else if (keycode == SPACE)
		data->keystate->space = 0;
	return (0);
}

// int update(t_data *data)
// {
// 	drawing(data);
// 	return 0;
// }

int update(t_book *record)
{
	t_data *data;
	static float	ticks_last_frame = 0.0;

	data = record->data;

	if (ticks_last_frame < 0.5)
		ticks_last_frame = (float) current_time_ms();
	while ((float) current_time_ms()
		- (ticks_last_frame + record->game->constants.frame_rate) < 0)
		;
	record->game->delta_time = (float)(current_time_ms() - ticks_last_frame) / 1000.0f;
	ticks_last_frame = (float)current_time_ms();
	printf("delta_time: %f\n", record->game->delta_time);
	// pause();
	player_movement(data->game); // player movement
	raycast(data, data->game);
	put_map(data);
	return 0;
}


// int	update(t_book *record)
// {
// 	t_game	*g;
// 	static float	ticks_last_frame = 0.0;

// 	g = record->game;
// 	g->delta_time = (float)(current_time_ms() - ticks_last_frame) / 1000.0f;
// 	ticks_last_frame = (float)current_time_ms();
// 	player_movement(g);
// 	raycast(record->data);
// 	return (0);
// }

void	game_init(t_game *g, t_book *record)
{
	// game->start_time = clock();
	// game->player->angle = 0;
	// game->player->speed = 100;
	// game->player->rot_speed = 90;
	// game->player->walk_direction = 0;
	// game->player->turn_direction = 0;
	// game->player->rotation_direction = 0;
	// game->player->map = game->map->arr;

	// g = record->game;
	g->mlx = record->data->mlx->mlx;
	g->win.img = record->data->mlx->win;
	g->frame.img = record->data->mlx->img;
	g->rays = record->data->rays;
	g->map = *record->map_table;
}

int	cub_render(t_book *record)
{
	static unsigned int	frames = 0;
	static unsigned int	last_fps = FPS;
	clock_t				elapsed_ticks;
	t_game				*g;

	g = record->game;	
	g->frame.img = mlx_new_image(g->mlx, g->win.width, g->win.height);
	g->frame.addr = mlx_get_data_addr(g->frame.img, &g->frame.bits_per_pixel,
			&g->frame.line_length, &g->frame.endian);
	frames++;
	elapsed_ticks = clock() - g->start_time;
	if (elapsed_ticks >= CLOCKS_PER_SEC)
	{
		last_fps = frames;
		frames = 0;
		g->start_time = clock();
	}
	update(record);
	mlx_put_image_to_window(g->mlx, g->win.img, g->frame.img, 0, 0);
	mlx_destroy_image(g->mlx, g->frame.img);
	return (RETURN_SUCCESS);
}


int	shut_exit(void)
{
	ft_putendl_fd("THANK YOU FOR PLAYING THIS GAME !", 1);
	exit(0);
	return (0);
}

void	hooking(t_mlx *mlx, t_book *record)
{
	t_data	*data;

	data = record->data;
	mlx_hook(mlx->win, DestroyNotify, NoEventMask, &shut_exit, record);
	mlx_hook(mlx->win, KeyPress, NoEventMask, &keypress, data);
	mlx_hook(mlx->win, KeyRelease, KeyPressMask, &keyrelease, data);
	mlx_hook(mlx->win, 02, 00, &keypress, data);
	mlx_hook(mlx->win, 03, 0L, &keyrelease, data);
	mlx_loop_hook(mlx->mlx, &cub_render, record);
	mlx_loop(data->mlx->mlx);
}

