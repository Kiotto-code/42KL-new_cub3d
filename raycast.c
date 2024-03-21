/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 23:20:49 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/21 16:22:40 by yichan           ###   ########.fr       */
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

void	raycast(t_data *data)
{
	t_coords	dist;
	float		delta_depth;	
	float		ray_angle;
	(void)dist;
	(void)delta_depth;
	int			i;
	
	ray_angle = data->player->angle - data->constant->half_fov + 0.0001;
	i = -1;
	while (++i < N_RAY) // there will be total of 1080 rays
	{
		data->rays[i].angle = ray_angle;
		data->rays[i].sin_a = sin(ray_angle);
		data->rays[i].cos_a = cos(ray_angle);

		printf(YELLOW);
		printf("%i sin ray = %f", i , data->rays[i].sin_a);
		printf("%i cos ray = %f", i , data->rays[i].cos_a);
		printf(RESET);
		
		find_hor_steps(data, i, &dist, &delta_depth);
		check_horz_inters(data, i, dist, delta_depth);
		find_vert_steps(data, i, &dist, &delta_depth);
		check_vert_inters(data, i, dist, delta_depth);
		final_inters(data, i);
		// draw_walls(data, it, ray_angle);
		ray_angle += data->constant->delta_angle; // each ray will add 0.0555555
	}
}