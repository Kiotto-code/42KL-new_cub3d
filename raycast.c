/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:20:49 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/24 07:55:29 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

bool	check_if_wall(int content)
{
	return (content == 1);
}

void	find_hor_steps(t_data *data, int i, t_coords *dist, float *depth)
{
	if (data->rays[i].sin_a > 0)
	{
		data->rays[i].horz_inters.y = (data->player->map_pos_y + 1) * CELL_SIZE;
		dist->y = CELL_SIZE;
	}
	else
	{
		data->rays[i].horz_inters.y = data->player->map_pos_y * CELL_SIZE - 0.0001;
		dist->y = -CELL_SIZE;
	}
	data->rays[i].depth_horz = data->rays[i].horz_inters.y - data->player->pos.y;
	data->rays[i].depth_horz /= data->rays[i].sin_a;
	data->rays[i].horz_inters.x = data->rays[i].depth_horz * data->rays[i].cos_a;
	data->rays[i].horz_inters.x += data->player->pos.x;
	*depth = dist->y / data->rays[i].sin_a;
	dist->x = *depth * data->rays[i].cos_a;
}

void	find_vert_steps(t_data *data, int i, t_coords *dist, float *depth)
{
	if (data->rays[i].cos_a > 0)
	{
		data->rays[i].vert_inters.x = (data->player->map_pos_x + 1) * CELL_SIZE;
		dist->x = CELL_SIZE;
	}
	else
	{
		data->rays[i].vert_inters.x = data->player->map_pos_x * CELL_SIZE - 0.0001;
		dist->x = -CELL_SIZE;
	}
	data->rays[i].depth_vert = data->rays[i].vert_inters.x - data->player->pos.x;
	data->rays[i].depth_vert /= data->rays[i].cos_a;
	data->rays[i].vert_inters.y = data->rays[i].depth_vert * data->rays[i].sin_a;
	data->rays[i].vert_inters.y += data->player->pos.y;
	*depth = dist->x / data->rays[i].cos_a;
	dist->y = *depth * data->rays[i].sin_a;
}

void	check_vert_inters(t_data *data, int i, t_coords dist, float depth)
{
	t_iterators	vert_tile;
	int			j;

	j = -1;
	while (++j < MAX_DEPTH)
	{
		vert_tile.j = abs((int)(data->rays[i].vert_inters.x / CELL_SIZE));
		vert_tile.i = abs((int)(data->rays[i].vert_inters.y / CELL_SIZE));
		if (vert_tile.i >= data->map_h || vert_tile.j >= data->map_w)
			break ;
		if (check_if_wall(data->map[vert_tile.i][vert_tile.j]))
		{
			data->rays[i].vert_wall_content = data->map[vert_tile.i][vert_tile.j];
			break ;
		}
		data->rays[i].vert_inters.x += dist.x;
		data->rays[i].vert_inters.y += dist.y;
		data->rays[i].depth_vert += depth;
	}
}

void	check_horz_inters(t_data *data, int i, t_coords dist, float depth)
{
	t_iterators	horz_tile;
	int			j;

	j = -1;
	while (++j < MAX_DEPTH)
	{
		horz_tile.j = abs((int)(data->rays[i].horz_inters.x / CELL_SIZE));
		horz_tile.i = abs((int)(data->rays[i].horz_inters.y / CELL_SIZE));
		if (horz_tile.i >= data->map_h || horz_tile.j >= data->map_w)
			break ;
		if (check_if_wall(data->map[horz_tile.i][horz_tile.j]))
		{
			data->rays[i].horz_wall_content = data->map[horz_tile.i][horz_tile.j];
			break ;
		}
		data->rays[i].horz_inters.x += dist.x;
		data->rays[i].horz_inters.y += dist.y;
		data->rays[i].depth_horz += depth;
	}
}


void	final_inters(t_data *data, int i)
{
	if (data->rays[i].depth_vert < data->rays[i].depth_horz)
	{
		data->rays[i].vert_inters.y = fmod(data->rays[i].vert_inters.y, CELL_SIZE);
		data->rays[i].depth = data->rays[i].depth_vert;
		data->rays[i].wall_hit = data->rays[i].vert_inters;
		data->rays[i].content_hit = data->rays[i].vert_wall_content;
		data->rays[i].vertical_hit = true;
	}
	else
	{
		data->rays[i].horz_inters.x = fmod(data->rays[i].horz_inters.x, CELL_SIZE);
		data->rays[i].depth = data->rays[i].depth_horz;
		data->rays[i].wall_hit = data->rays[i].horz_inters;
		data->rays[i].content_hit = data->rays[i].horz_wall_content;
		data->rays[i].vertical_hit = false;
	}
}

void	raycast(t_data *data, t_game *g)
{
	t_coords	dist;
	float		delta_depth;
	float		ray_angle;
	t_iterators	it;

	g->player.map_pos.x = (int)(g->player.pos.x / TILE_SIZE);
	g->player.map_pos.y = (int)(g->player.pos.y / TILE_SIZE);
	printf("g->player.map_pos.x : %f\n", g->player.map_pos.x);
	printf("g->player.map_pos.y : %f\n", g->player.map_pos.y);
	// pause();
	ray_angle = g->player.angle - g->constants.half_fov + 0.0001;
	it.i = -1;
	while (++it.i < NUM_RAYS)
	{
		printf("ray_angle = %f\n", ray_angle);
		printf("it.i = %d\n", it.i);
		g->rays[it.i].angle = ray_angle;
		g->rays[it.i].sin_a = sin(ray_angle);
		g->rays[it.i].cos_a = cos(ray_angle);
		find_hor_steps(data, it.i, &dist, &delta_depth);
		check_horz_inters(data, it.i, dist, delta_depth);
		find_vert_steps(data, it.i, &dist, &delta_depth);
		check_vert_inters(data, it.i, dist, delta_depth);
		final_inters(data, it.i);
		draw_walls(g, it, ray_angle);
		ray_angle += g->constants.delta_angle;
	}
	// mlx_put_image_to_window(g->mlx, g->win.img, g->frame.img, 0, 0);
}
