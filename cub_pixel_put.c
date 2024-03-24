/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:53:09 by absalhi           #+#    #+#             */
/*   Updated: 2024/03/23 20:38:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	create_rgb(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

void	cub_pixel_put(t_game *g, float x, float y, int color)
{
	t_mlx	*image;
	char	*dst;
	int		int_x;
	int		int_y;

	image = &g->frame;
	int_x = (int)round(x);
	int_y = (int)round(y);
	// printf("int_x: %d, int_y: %d\n", int_x, int_y);
	if (x < 0 || x > g->win.width || y < 0 || y > g->win.height)
		return ;
	dst = image->addr + (int_y * image->line_length
			+ int_x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
