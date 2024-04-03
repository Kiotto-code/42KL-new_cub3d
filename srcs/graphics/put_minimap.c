/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:04:15 by etlaw             #+#    #+#             */
/*   Updated: 2024/04/02 22:46:19 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	strchr_v2(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_mlx_put_px(t_data *data, int x, int y, unsigned long color)
{
	char	*dst;

	if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->img->data + (y * data->img->size_l + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_player(t_data *data, t_vector pos)
{
	ft_mlx_put_px(data, pos.x / data->cell_size,
		pos.y / data->cell_size, 0xff0000);
	ft_mlx_put_px(data, pos.x / data->cell_size + 1,
		pos.y / data->cell_size, 0xff0000);
	ft_mlx_put_px(data, pos.x / data->cell_size,
		pos.y / data->cell_size + 1, 0xff0000);
	ft_mlx_put_px(data, pos.x / data->cell_size + 1,
		pos.y / data->cell_size + 1, 0xff0000);
}

void	color_sqr(t_data *data, int x, int y, unsigned int color)
{
	int	xc;
	int	yc;

	xc = 0;
	while (xc <= data->cell_size)
	{
		yc = 0;
		while (yc <= data->cell_size)
		{
			if (yc == 0 || xc == 0)
				ft_mlx_put_px(data, xc + (data->cell_size * x),
					yc + (data->cell_size * y), 0x0);
			else
				ft_mlx_put_px(data, xc + (data->cell_size * x),
					yc + (data->cell_size * y), color);
			yc++;
		}
		xc++;
	}
	put_player(data, data->player.pos);
}

void	put_minimap(t_data *data)
{
	int	x;
	int	y;

	data->cell_size = 10;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (strchr_v2(data->map[y][x], "1"))
				color_sqr(data, x, y, 0x0);
			else if (strchr_v2(data->map[y][x], "0"))
				color_sqr(data, x, y, 0xd0d0d0);
			else if (strchr_v2(data->map[y][x], "C"))
				color_sqr(data, x, y, 0xff0000);
			else if (strchr_v2(data->map[y][x], "O"))
				color_sqr(data, x, y, 0x5beb34);
			x++;
		}
		y++;
	}
}
