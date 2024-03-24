/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:15:59 by yichan            #+#    #+#             */
/*   Updated: 2024/03/24 08:52:04 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "raycast.h"

// bool	check_if_wall(int content)
// {
// 	return (content == 1);
// }

bool	has_wall_at(t_game *g, float x, float y)
{
	if (x < 0 || x > g->map.width * TILE_SIZE
		|| y < 0 || y > g->map.height * TILE_SIZE)
		return (true);
	return (check_if_wall(
			g->map.arr[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)]));
}

void	check_wall_collision(t_game *g, float dx, float dy)
{
	if (!has_wall_at(g, g->player.pos.x + dx * PLAYER_SCALE, g->player.pos.y))
		g->player.pos.x += dx;
	if (!has_wall_at(g, g->player.pos.x, g->player.pos.y + dy * PLAYER_SCALE))
		g->player.pos.y += dy;
}

int	player_movement(t_game *g)
{
	t_coords	diff;
	float		speed;
	float		speed_sin;
	float		speed_cos;

	diff.x = 0;
	diff.y = 0;
	speed = g->player.speed * g->delta_time;
	speed_sin = speed * sin(g->player.angle);
	speed_cos = speed * cos(g->player.angle);
	diff.x += -speed_cos * g->player.walk_direction;
	diff.y += -speed_sin * g->player.walk_direction;
	diff.x += -speed_sin * g->player.turn_direction;
	diff.y += speed_cos * g->player.turn_direction;
	printf("diff.x, diff.y = %f, %f\n", diff.x, diff.y);
	// pause();
	check_wall_collision(g, diff.x, diff.y);
	printf("player_angle = %f\n", g->player.angle);
	// pause();
	g->player.angle += g->player.rot_speed * g->delta_time
		* g->player.rotation_direction;
	printf("g->player.rot_speed, g->delta_time, g->player.rotation_direction = %f, %f, %d\n", g->player.rot_speed, g->delta_time, g->player.rotation_direction);
	// pause();
	printf("g->constants.tau = %f\n", g->constants.tau);
	g->player.angle = fmod(g->player.angle, g->constants.tau);
	printf("g->player.angle = %f\n", g->player.angle);
	// pause();
	return (RETURN_SUCCESS);
}