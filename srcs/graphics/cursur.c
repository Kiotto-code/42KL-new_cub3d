/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:29:00 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 10:15:22 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_img *image, t_offset offset, unsigned int color)
{
	char	*dst;

	dst = image->data + (offset.y * image->size_l + offset.x
			* (image->bpp / 8));
	if (image->endian == 1)
		*(unsigned int *)dst = convert_endian(color);
	else
		*(unsigned int *)dst = color;
}

void	fill_pixel(t_texture *image, t_offset xy, int size, t_rgba color)
{
	int				i;
	int				j;
	int				x;
	int				y;
	unsigned int	color_int;

	color_int = color.rgba;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			x = xy.x + i;
			y = xy.y + j;
			if (x >= 0 && x < image->width && y >= 0 && y < image->height)
				put_pixel(image->img, (t_offset){.x = x, .y = y}, color_int);
		}
	}
}

void	image_init(t_img *original_image, t_texture *resized_image, \
	int new_width, int new_height)
{
	t_img			*img;

	img = resized_image->img;
	resized_image->width = new_width;
	resized_image->height = new_height;
	resized_image->img->ptr = mlx_new_image(original_image->ptr, \
		new_width, new_height);
	resized_image->img->data = mlx_get_data_addr \
		(resized_image->img->ptr, &img->bpp, &img->size_l, &img->endian);
}

void	rescale_pixel(t_texture *resized_image, t_texture *original_texture, \
	t_img *original_image, unsigned int color)
{
	float	x_scale;
	float	y_scale;
	int		y;
	int		x;

	x_scale = (float)original_texture->width / resized_image->width;
	y_scale = (float)original_texture->height / resized_image->height;
	y = -1;
	while (++y < resized_image->height)
	{
		x = -1;
		while (++x < resized_image->width)
		{
			color = *(unsigned int *)(original_image->data
					+ (y * (int)y_scale * original_image->size_l
						+ x * (int)x_scale * (original_image->bpp / 8)));
			fill_pixel(resized_image, (t_offset){.x = x, .y = y}, \
				1, (t_rgba){.rgba = color});
		}
	}
}

t_texture	resize_image(t_texture *original_texture, \
	int new_width, int new_height)
{
	t_texture		resized_image;
	t_img			*original_image;
	t_img			*img;
	unsigned int	color;

	color = 0;
	original_image = original_texture->img;
	resized_image.img = malloc(sizeof(t_img));
	img = resized_image.img;
	image_init(original_image, &resized_image, new_width, new_height);
	rescale_pixel(&resized_image, original_texture, original_image, color);
	return (resized_image);
}

// void	put_cursur(t_data *data)
// {
// 	t_texture	resized_img;

// 	resized_img = resize_image(&data->cursur, CURSOR_SIZE, CURSOR_SIZE);
// 	mlx_put_image_to_window(data->mlx, data->win, resized_img.img->ptr, \
// 		(SCREEN_WIDTH - CURSOR_SIZE)/2, (SCREEN_HEIGHT - CURSOR_SIZE)/2);
// 	free_1_texture(&resized_img);
// }