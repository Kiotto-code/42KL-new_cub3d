/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:19:58 by etlaw             #+#    #+#             */
/*   Updated: 2024/04/01 22:17:48 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_gun(t_data *data)
{
	data->gun[0] = "./textures/gun/gun_1.xpm";
	data->gun[1] = "./textures/gun/gun_2.xpm";
	data->gun[2] = "./textures/gun/gun_3.xpm";
	data->gun[3] = "./textures/gun/gun_4.xpm";
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

void put_gun(t_data *data)
{
	void			*img;
	int				x;
	int				y;
	float	static 	i;
	
	img = mlx_xpm_file_to_image(data->mlx, data->gun[0], &x, &y);
	if (data->shoot == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			img, (SCREEN_WIDTH / 2) - 70 , SCREEN_HEIGHT - 128);
	else if (data->shoot == 1)
	{
		img = mlx_xpm_file_to_image(data->mlx, data->gun[(int)i], &x, &y);
		mlx_put_image_to_window(data->mlx, data->win,
			img, (SCREEN_WIDTH / 2) - 70 , SCREEN_HEIGHT - 128);
		i += 0.5;
	}
	if (i >= 4)
		i = 0;
}

 