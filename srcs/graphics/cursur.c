/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:29:00 by yichan            #+#    #+#             */
/*   Updated: 2024/04/01 21:42:30 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

unsigned int	convert_endian(unsigned int color)
{
	t_rgba	tmp;
	t_rgba	new;

	tmp.rgba = color;
	new = (t_rgba){.b=tmp.a, .g=tmp.r, .r=tmp.g, .a=tmp.b};
	return (new.rgba);
}

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

void fill_pixel(t_texture *image, t_offset xy, int size, t_rgba color)
{
    int i, j;
    unsigned int color_int = color.rgba;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            int x = xy.x + i;
            int y = xy.y + j;

            if (x >= 0 && x < image->width && y >= 0 && y < image->height)
            {
                put_pixel(image->img, (t_offset){.x = x, .y = y}, color_int);
            }
        }
    }
}

t_texture resize_image(t_texture *original_texture, int new_width, int new_height)
{
    t_texture	resized_image;
	t_img		*original_image;
	t_img 		*img;

    // Create a new image with the desired dimensions
	original_image = original_texture->img;
	resized_image.img = malloc(sizeof(t_img));
	img = resized_image.img;
    resized_image.width = new_width;
    resized_image.height = new_height;
    resized_image.img->ptr = mlx_new_image(original_image->ptr, new_width, new_height);
    resized_image.img->data = mlx_get_data_addr(resized_image.img->ptr, &img->bpp, &img->size_l, &img->endian);

    // Scale factor for width and height
    float x_scale = (float)original_texture->width / new_width;
    float y_scale = (float)original_texture->height / new_height;


    // Copy pixels from the original image to the resized image
    for (int y = 0; y < new_height; y++)
    {
        for (int x = 0; x < new_width; x++)
        {
            int original_x = (int)(x * x_scale);
            int original_y = (int)(y * y_scale);

            unsigned int color = 
				*(unsigned int *)(original_image->data + 
				(original_y * original_image->size_l + 
				original_x * (original_image->bpp / 8)));
            fill_pixel(&resized_image, (t_offset){.x = x, .y = y}, 1, (t_rgba){.rgba = color});
        }
    }

    return resized_image;
}

void	put_cursur(t_data *data)
{
	t_texture resized_img;
	
	resized_img = resize_image(&data->cursur, CURSOR_SIZE, CURSOR_SIZE);
	mlx_put_image_to_window(data->mlx, data->win, resized_img.img->ptr, \
		(SCREEN_WIDTH - CURSOR_SIZE)/2, (SCREEN_HEIGHT - CURSOR_SIZE)/2);
	free_1_texture(&resized_img);
}