/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:38:29 by yichan            #+#    #+#             */
/*   Updated: 2024/04/02 22:37:57 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ray_wall(t_data *data, t_vector pos)
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
	else if (ft_strchr("0", data->map[x][y]))
		return (false);
	else if (ft_strchr("O", data->map[x][y]))
		return (false);
	else if (ft_strchr("C", data->map[x][y]))
	{
		data->door_state = CLOSE;
		return (true);
	}
	return (true);
}

void	print_credits(void)
{
	printf(RED);
	printf("   ___      _    _____     _ \n");
	printf("  / __\\   _| |__|___ /  __| |\n");
	printf(" / / | | | | '_ \\ |_ \\ / _` |\n");
	printf("/ /__| |_| | |_) |__) | (_| |\n");
	printf("\\____/\\__,_|_.__/____/ \\__,_|\n");
	printf("\n            cub3d          \n\n");
	printf("        by: etlaw            \n");
	printf("            yichan            \n");
}

int	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	free_data(data);
	print_credits();
	exit(0);
}

void	pause_game(t_data *data)
{
	if (data->pause == false)
		mlx_mouse_show();
	else
		mlx_mouse_hide();
	data->pause = !(data->pause);
}

int	game_loop(void *data2)
{
	t_data	*data;

	data = (t_data *)data2;
	if (data->pause == false)
	{
		mlx_do_key_autorepeaton(data->mlx);
		move(data, data->player.movement);
		ray_the_caster(data);
		put_minimap(data);
		mlx_put_image_to_window(data->mlx, data->win, \
							data->canvas.img->ptr, 0, 0);
		put_cursur(data);
		put_gun(data);
		check_mouse_movement(data);
		mlx_hook(data->win, KEY_PRESS, KeyPressMask, move_on_press, data);
		mlx_hook(data->win, KEY_RELEASE, KeyPressMask, move_on_release, data);
		mlx_hook(data->win, RED_CROSS, 0, x_close, data);
		mlx_hook(data->win, 04, 0L, &left_press, data);
		mlx_hook(data->win, 05, 0L, &left_release, data);
	}
	return (0);
}
