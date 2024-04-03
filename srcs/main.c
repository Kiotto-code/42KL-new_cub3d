/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:43 by yichan            #+#    #+#             */
/*   Updated: 2024/04/02 23:09:02 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	init(&data);
	init_image(&data, data.canvas.img);
	init_gun(&data);
	mlx_mouse_hide();
	data.texture->height = 0;
	data.texture->width = 0;
	error_check(&data, argc, argv);
	data.canvas.height = data.map_height * TILE;
	data.canvas.width = data.map_width * TILE;
	data.mid_canvas.x = SCREEN_WIDTH / 2;
	data.mid_canvas.y = SCREEN_HEIGHT / 2;
	mlx_mouse_move(data.win, data.mid_canvas.x, data.mid_canvas.y);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
