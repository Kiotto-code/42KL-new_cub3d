/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:19:58 by etlaw             #+#    #+#             */
/*   Updated: 2024/04/06 18:49:18 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_gun(t_data *data)
{
	int	x;
	int	y;

	data->gun[0] = "./textures/gun/gun_1.xpm";
	data->gun[1] = "./textures/gun/gun_2.xpm";
	data->gun[2] = "./textures/gun/gun_3.xpm";
	data->gun[3] = "./textures/gun/gun_4.xpm";
	data->gun_img[0] = mlx_xpm_file_to_image(data->mlx, data->gun[0], &x, &y);
	data->gun_img[1] = mlx_xpm_file_to_image(data->mlx, data->gun[0], &x, &y);
	data->gun_img[2] = mlx_xpm_file_to_image(data->mlx, data->gun[0], &x, &y);
	data->gun_img[3] = mlx_xpm_file_to_image(data->mlx, data->gun[0], &x, &y);
}

int	left_press(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == LEFT_CLICK)
		data->shoot = 1;
	return (0);
}

int	left_release(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == LEFT_CLICK)
		data->shoot = 0;
	return (0);
}

void	put_gun(t_data *data)
{
	static float	i;
	void			*img;
	int				x;
	int				y;

	if (data->shoot == 0)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->gun_img[0], (SCREEN_WIDTH / 2) - 70, SCREEN_HEIGHT - 128);
	}
	else if (data->shoot == 1)
	{
		// mlx_put_image_to_window(data->mlx, data->win,
		// 	data->gun_img[1], (SCREEN_WIDTH / 2) - 70, SCREEN_HEIGHT - 128);
		// printf("fire\n");
		i += 1;
		img = mlx_xpm_file_to_image(data->mlx, data->gun[(int)i], &x, &y);
		mlx_put_image_to_window(data->mlx, data->win,
			img, (SCREEN_WIDTH / 2) - 70, SCREEN_HEIGHT - 128);
		i += 0.5;
	}
	if (i >= 3)
		i = 0;
}

void	put_cursur(t_data *data)
{
	t_texture	resized_img;

	resized_img = resize_image(&data->cursur, CURSOR_SIZE, CURSOR_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, resized_img.img->ptr, \
		(SCREEN_WIDTH - CURSOR_SIZE) / 2, (SCREEN_HEIGHT - CURSOR_SIZE) / 2);
	free_1_texture(&resized_img);
}
