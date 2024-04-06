/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:38:38 by yichan            #+#    #+#             */
/*   Updated: 2024/04/02 22:45:08 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	open_close_door(t_data *data, t_player *player)
{
	t_vector	p;
	t_vector	temp;
	int			x;
	int			y;

	temp.x = player->dir.x * DOOR_DETECT;
	temp.y = player->dir.y * DOOR_DETECT;
	p = vector_add(player->pos, temp);
	if (p.x < 0 || p.y < 0 || p.x > (data->map_width * TILE)
		|| p.y > (data->map_height * TILE))
		return ;
	x = p.y / TILE;
	y = p.x / TILE;
	if (ft_strchr("CO", data->map[x][y]) == NULL)
		return ;
	if (data->map[x][y] == 'O')
	{
		data->map[x][y] = 'C';
	}
	else if (data->map[x][y] == 'C')
	{
		data->map[x][y] = 'O';
	}
}

bool	is_wall(t_data *data, t_vector pos)
{
	int	x;
	int	y;

	x = pos.y / TILE;
	y = pos.x / TILE;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (ft_strchr("1", data->map[x][y]))
		return (true);
	if (ft_strchr("0", data->map[x][y]))
		return (false);
	if (ft_strchr("O", data->map[x][y]))
		return (false);
	if (ft_strchr("C", data->map[x][y]))
		return (true);
	return (true);
}

void	move_check(t_data *data, int movement, t_vector temp)
{
	if (movement & UP && !is_wall(data, \
		vector_add(data->player.pos, data->player.dir)))
		data->player.pos = vector_add(data->player.pos, temp);
	else if (movement & DOWN && !is_wall(data, \
		vector_substr(data->player.pos, data->player.dir)))
		data->player.pos = vector_substr(data->player.pos, temp);
	else if (movement & RIGHT && !is_wall(data, \
		vector_add(data->player.pos, rotatevector(data->player.dir, 90))))
		data->player.pos = vector_add(data->player.pos, \
								rotatevector(temp, 90));
	else if (movement & LEFT && !is_wall(data, vector_substr(data->player.pos, \
									rotatevector(data->player.dir, 90))))
		data->player.pos = vector_substr(data->player.pos, \
									rotatevector(temp, 90));
	if (movement & TURN_LEFT)
		data->player.dir = rotatevector(data->player.dir, -ROTATE * 50);
	if (movement & TURN_RIGHT)
		data->player.dir = rotatevector(data->player.dir, ROTATE * 50);
}

void	move(t_data *data, int movement)
{
	t_vector	temp;
	double		speed;

	speed = data->speed;
	if (speed > 0.9)
		speed = 0.9;
	temp.x = data->player.dir.x * speed;
	temp.y = data->player.dir.y * speed;
	move_check(data, movement, temp);
}

void	check_mouse_movement(t_data *data)
{
	t_intvector	mouse;

	mlx_mouse_get_pos(data->win, &mouse.x, &mouse.y);
	if (mouse.x < data->mid_canvas.x)
		data->player.dir = rotatevector(data->player.dir, \
							(data->mid_canvas.x - mouse.x) * -ROTATE);
	else if (mouse.x > data->mid_canvas.x)
		data->player.dir = rotatevector(data->player.dir, \
							(mouse.x - data->mid_canvas.x) * ROTATE);
	mlx_mouse_move(data->win, data->mid_canvas.x, data->mid_canvas.y);
}
