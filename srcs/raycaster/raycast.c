/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:53:53 by yichan            #+#    #+#             */
/*   Updated: 2024/04/02 00:55:50 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	end_condition(t_data *data, t_vector vector)
{
	if (vector.x < 0 || vector.y < 0 || vector.x > (data->map_width * TILE)
		|| vector.y > (data->map_height * TILE))
		return (OUT_BOUNDS);
	return (ray_wall(data, vector));
}

double	horizontal_raycast(t_data *data, t_vector direction)
{
	int			cond;
	double		ratio;
	t_vecstack	vec;

	if (direction.y == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	vec.strich.y = direction_check(data, direction, vec.strich.y, 1);
	vec.tmp.y = ft_abs(direction.y);
	vec.tmp.x = direction.x;
	ratio = vec.tmp.y / vec.strich.y;
	vec.strich.x = vec.tmp.x / ratio;
	vec.strich = dir_smoler_zero(direction, vec.strich, 1);
	vec.first_inter.x = data->player.pos.x + vec.strich.x;
	vec.first_inter.y = data->player.pos.y + vec.strich.y;
	cond = end_condition(data, vec.first_inter);
	if (direction.y < 0)
		vec.strich.y += 0.001;
	if (cond == 0)
		vec.first_inter = cond_horiz_zero(data, vec, direction, ratio);
	data->wall.pos.x = fabs(vec.first_inter.x);
	ratio = ratio_is_actually_distance(data, ratio, vec.first_inter, cond);
	return (ratio);
}

double	vertical_raycast(t_data *data, t_vector direction)
{
	int			cond;
	double		ratio;
	t_vecstack	vec;

	if (direction.x == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	vec.strich.x = direction_check(data, direction, vec.strich.x, 0);
	vec.tmp.x = ft_abs(direction.x);
	vec.tmp.y = direction.y;
	ratio = vec.tmp.x / vec.strich.x;
	vec.strich.y = vec.tmp.y / ratio;
	vec.strich = dir_smoler_zero(direction, vec.strich, 0);
	vec.first_inter.x = data->player.pos.x + vec.strich.x;
	vec.first_inter.y = data->player.pos.y + vec.strich.y;
	cond = end_condition(data, vec.first_inter);
	if (direction.x < 0)
		vec.strich.x += 0.001;
	if (cond == 0)
		vec.first_inter = cond_vert_zero(data, vec, direction, ratio);
	data->wall.pos.y = vec.first_inter.y;
	ratio = ratio_is_actually_distance(data, ratio, vec.first_inter, cond);
	return (ratio);
}

void	single_ray(t_data *data, t_vector direction)
{
	double	horizontal_dist;
	double	vertikal_dist;
	double	actual_dist;

	vertikal_dist = vertical_raycast(data, direction);
	horizontal_dist = horizontal_raycast(data, direction);
	if (horizontal_dist > vertikal_dist)
	{
		if (direction.x < 0)
			data->wall.direction = WEST;
		else
			data->wall.direction = EAST;
		actual_dist = vertikal_dist;
	}
	else
	{
		if (direction.y < 0)
			data->wall.direction = NORTH;
		else
			data->wall.direction = SOUTH;
		actual_dist = horizontal_dist;
	}
	data->wall.distance = actual_dist / TILE;
}

bool	ray_door(t_data *data, t_vector pos)
{
	int	x;
	int	y;
	
	if (pos.x < 0 || pos.y < 0 || pos.x > (data->map_width * TILE)
		|| pos.y > (data->map_height * TILE))
		return (OUT_BOUNDS);
	x = pos.y / TILE;
	y = pos.x / TILE;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (data->map[x][y] == 'O')
		return (true);
	if (data->map[x][y] == 'C')
		return (true);
	return (false);
}


void	ray_the_caster(t_data *data)
{
	t_vector	init_pos;
	t_vector	tmp;
	t_intvector	draw;

	init_pos = get_init_pos(data->player);
	draw.x = 0;
	draw.y = 0;
	while (draw.x < RAY_COUNT)
	{
		data->door_state = 0;
		tmp = rotatevector(vector_substr(init_pos, data->player.pos), \
							get_next_angle(init_pos, data->player, draw.x));
		single_ray(data, tmp);
		if (draw.x != RAY_COUNT / 2)
			data->wall.distance *= vec_dot(data->player.dir, tmp);
		if (data->door_state == 0)
			draw_vertical_line(data, &(data->texture)
				[data->wall.direction], &data->wall, draw);
		else if (data->door_state == OPEN)
			draw_vertical_line(data, &data->open_door
			, &data->wall, draw);
		else if(data->door_state == CLOSE)
			draw_vertical_line(data, &data->close_door
			, &data->wall, draw);
		draw.x++;
	}
}
