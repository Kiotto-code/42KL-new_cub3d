/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:38:44 by yichan            #+#    #+#             */
/*   Updated: 2024/04/02 22:56:33 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned int	convert_endian(unsigned int color)
{
	t_rgba	tmp;
	t_rgba	new;

	tmp.rgba = color;
	new = (t_rgba){.b = tmp.a, .g = tmp.r, .r = tmp.g, .a = tmp.b};
	return (new.rgba);
}

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img->data + (y * data->img->size_l + x * (data->img->bpp / 8));
	*(uint32_t *)dst = color;
}

uint32_t	my_mlx_pixel_get(t_texture *texture, int x, int y)
{
	char	*dst;

	if (y >= texture->height && texture->height != 0)
		y = texture->height - 1;
	if (x >= texture->width && texture->width != 0)
		x = texture->width - 1;
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return (0);
	dst = texture->img->data
		+ (y * texture->img->size_l + x * (texture->img->bpp / 8));
	return (*(uint32_t *)dst);
}
