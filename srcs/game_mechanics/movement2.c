/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:39:28 by etlaw             #+#    #+#             */
/*   Updated: 2024/04/02 22:40:29 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	move_on_press(int keycode, t_data *data)
{
	if (keycode == Q_KEY)
		data->expand = 1;
	if (keycode == SPACE)
		pause_game(data);
	if (keycode == E_KEY)
		open_close_door(data, &data->player);
	if (keycode == ESC)
		x_close(data);
	else if (keycode == W_KEY)
		data->player.movement = data->player.movement | UP;
	else if (keycode == S_KEY)
		data->player.movement = data->player.movement | DOWN;
	else if (keycode == D_KEY)
		data->player.movement = data->player.movement | RIGHT;
	else if (keycode == A_KEY)
		data->player.movement = data->player.movement | LEFT;
	else if (keycode == ARROW_LEFT)
		data->player.movement = data->player.movement | TURN_LEFT;
	else if (keycode == ARROW_RIGHT)
		data->player.movement = data->player.movement | TURN_RIGHT;
	return (0);
}

int	move_on_release(int keycode, t_data *data)
{
	if (keycode == Q_KEY)
		data->expand = 0;
	else if (keycode == W_KEY)
		data->player.movement = data->player.movement & ~UP;
	else if (keycode == S_KEY)
		data->player.movement = data->player.movement & ~DOWN;
	else if (keycode == D_KEY)
		data->player.movement = data->player.movement & ~RIGHT;
	else if (keycode == A_KEY)
		data->player.movement = data->player.movement & ~LEFT;
	else if (keycode == ARROW_LEFT)
		data->player.movement = data->player.movement & ~TURN_LEFT;
	else if (keycode == ARROW_RIGHT)
		data->player.movement = data->player.movement & ~TURN_RIGHT;
	return (0);
}
