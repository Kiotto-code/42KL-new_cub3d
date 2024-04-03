/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:38 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 23:56:44 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->speed = SPEED;
	data->pause = false;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "yo");
	if (!data->win)
		errno(WIN, "", data);
	data->texture[NORTH].img = ft_calloc(1, sizeof(t_img));
	data->texture[SOUTH].img = ft_calloc(1, sizeof(t_img));
	data->texture[EAST].img = ft_calloc(1, sizeof(t_img));
	data->texture[WEST].img = ft_calloc(1, sizeof(t_img));
	data->cursur.img = ft_calloc(1, sizeof(t_img));
	data->open_door.img = ft_calloc(1, sizeof(t_img));
	data->close_door.img = ft_calloc(1, sizeof(t_img));
	data->canvas.img = ft_calloc(1, sizeof(t_img));
	init_texture(data, &data->cursur, CURSUR_PATH);
	// init_texture(data, &data->open_door, O_DOOR_PATH);
	init_texture(data, &data->close_door, C_DOOR_PATH);
}

void	init_image(t_data *data, t_img *img)
{
	img->ptr = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->ptr)
		errno(IMG_FAIL, "canvas", data);
	img->data = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->size_l, &img->endian);
	data->img = img;
}

void	init_texture(t_data *data, t_texture *texture, char *path)
{
	texture->img->ptr = mlx_xpm_file_to_image(data->mlx, path, \
						&texture->width, &texture->height);
	if (!texture->img->ptr)
		errno(TEXTURE, path, data);
	texture->img->data = mlx_get_data_addr(texture->img->ptr, \
		&texture->img->bpp, &texture->img->size_l, &texture->img->endian);
}
