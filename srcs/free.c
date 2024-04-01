/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:33 by yichan            #+#    #+#             */
/*   Updated: 2024/03/31 12:51:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/cub3d.h"

void	free_texture(t_texture *texture)
{
	size_t	i;

	i = 0;
	while (i < TEXTCOUNT)
	{
		if (texture[i].img->ptr)
			free(texture[i].img->ptr);
		if (texture[i].img->data)
			free(texture[i].img->data);
		if (texture[i].img)
			free(texture[i].img);
		i++;
	}
}

void	free_1_texture(t_texture *texture)
{
		if (texture->img->ptr)
			free(texture->img->ptr);
		if (texture->img->data)
			free(texture->img->data);
		if (texture->img)
			free(texture->img);
}

void	free_data(t_data *data)
{
	// if (data->mlx)
	// 	free(data->mlx);
	if (data->win)
		free(data->win);
	if (data->map)
		free_2d(data->map);
	free_texture(data->texture);
	free_1_texture(&data->cursur);
	free_1_texture(&data->open_door);
	free_1_texture(&data->close_door);
	free_1_texture(&data->canvas);

	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	// if (data->cursur.img->ptr)
	// 	free(data->cursur.img->ptr);
}
