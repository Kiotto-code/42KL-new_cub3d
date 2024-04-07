/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:53:53 by yichan            #+#    #+#             */
/*   Updated: 2024/04/07 20:59:34 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	horizontal_raycast(t_data *data, t_vector direction)
{
	int			cond;
	double		ratio;
	t_vecstack	vec;

	if (direction.y == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	vec.dist.y = direction_check(data, direction, vec.dist.y, 1);
	vec.tmp.y = ft_abs(direction.y);
	vec.tmp.x = direction.x;
	ratio = vec.tmp.y / vec.dist.y;
	vec.dist.x = vec.tmp.x / ratio;
	vec.dist = dir_smoler_zero(direction, vec.dist, 1);
	vec.first_inter.x = data->player.pos.x + vec.dist.x;
	vec.first_inter.y = data->player.pos.y + vec.dist.y;
	cond = end_condition(data, vec.first_inter);
	if (direction.y < 0)
		vec.dist.y += 0.001;
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
	vec.dist.x = direction_check(data, direction, vec.dist.x, 0);
	vec.tmp.x = ft_abs(direction.x);
	vec.tmp.y = direction.y;
	ratio = vec.tmp.x / vec.dist.x;
	vec.dist.y = vec.tmp.y / ratio;
	vec.dist = dir_smoler_zero(direction, vec.dist, 0);
	vec.first_inter.x = data->player.pos.x + vec.dist.x;
	vec.first_inter.y = data->player.pos.y + vec.dist.y;
	cond = end_condition(data, vec.first_inter);
	if (direction.x < 0)
		vec.dist.x += 0.001;
	if (cond == 0)
		vec.first_inter = cond_vert_zero(data, vec, direction, ratio);
	data->wall.pos.y = vec.first_inter.y;
	ratio = ratio_is_actually_distance(data, ratio, vec.first_inter, cond);
	return (ratio);
}

void	single_ray(t_data *data, t_vector direction)
{
	double	horizontal_dist;
	double	vertical_dist;
	double	actual_dist;

	vertical_dist = vertical_raycast(data, direction);
	horizontal_dist = horizontal_raycast(data, direction);
	if (horizontal_dist > vertical_dist)
	{
		if (direction.x < 0)
			data->wall.direction = WEST;
		else
			data->wall.direction = EAST;
		actual_dist = vertical_dist;
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

void	raycaster(t_data *data)
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
		draw_vertical_line(data, &(data->texture)
		[data->wall.direction], &data->wall, draw);
		draw.x++;
	}
}
