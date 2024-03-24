/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:42:58 by etlaw             #+#    #+#             */
/*   Updated: 2024/03/24 09:05:22 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// void	ft_mlx_put_px(t_mlx *mlx, int x, int y, unsigned long color)
// {
// 	char	*dst;

// 	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
// 		return ;
// 	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
void	ft_mlx_put_px(t_mlx *mlx, float f_x, float f_y, unsigned long color)
{
	char	*dst;
	int		x;
	int		y;

	x = (int)round(f_x);
	y = (int)round(f_y);
	if (x >= WIN_W || y >= WIN_H || x < 0 || y < 0)
		return ;
	// printf("x: %d, y: %d\n", x, y);
	// printf("mlx->line_length: %d\n", mlx->line_length);
	// printf("mlx->bits_per_pixel: %d\n", mlx->bits_per_pixel);
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
				ft_mlx_put_px(data->mlx, xc + (data->cell_size * x),
					yc + (data->cell_size * y), 0x0);
			else
				ft_mlx_put_px(data->mlx, xc + (data->cell_size * x),
					yc + (data->cell_size * y), color);
			yc++;
		}
		xc++;
	}
}
// void	color_sqr(t_data *data, int x, int y, unsigned int color)
// {
// 	int	xc;
// 	int	yc;

// 	xc = 0;
// 	while (xc <= data->cell_size)
// 	{
// 		yc = 0;
// 		while (yc <= data->cell_size)
// 		{
// 			if (yc == 0 || xc == 0)
// 				ft_mlx_put_px(data->mlx, xc + (data->cell_size * x),
// 					yc + (data->cell_size * y), 0x0);
// 			else
// 				ft_mlx_put_px(data->mlx, xc + (data->cell_size * x),
// 					yc + (data->cell_size * y), color);
// 			yc++;
// 		}
// 		xc++;
// 	}
// }

void	ft_color_win(t_data *data, t_mlx *mlx, int ray_h)
{
	(void)data;
	int	x;
	int	y;

	x = 0;
	// printf("ray_h: %d\n", ray_h);
	// pause();
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			if (y > WIN_H / 2 + ray_h)
			{
				ft_mlx_put_px(mlx, x, y, 0x00f310);
				y++;
			}
			else
			{
				// printf("x: %d, y: %d\n", x, y);
				ft_mlx_put_px(mlx, x, y, 0x00f310);
				y++;
			}
		}
		x++;
	}
	// pause();
}


int	ft_is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	put_map(t_data *data)
{
	int	x;
	int	y;

	if (data->keystate->space)
		data->cell_size = PLAYER_MINIMAP_WIDTH * 2; // how big the map will expand
	else
		data->cell_size = PLAYER_MINIMAP_WIDTH; // else map will be this big
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("C1", data->map[y][x]))
				color_sqr(data, x, y, 0x0);
			else if (!ft_is_whitespace(data->map[y][x]))
				color_sqr(data, x, y, 0xd2b4de);
			x++;
		}
		y++;
	}
	// put_rays(data, (double)CELL_SIZE / data->cell_size);
	// mlx_put_image_to_window(data->mlx->mlx,
	// 	data->mlx->win, data->mlx->img, 0, 0);
}

// void	put_map(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	t_game *g;

// 	g = data->game;	
// 	if (data->keystate->space)
// 		data->cell_size = PLAYER_MINIMAP_WIDTH * 2; // how big the map will expand
// 	else
// 		data->cell_size = PLAYER_MINIMAP_WIDTH; // else map will be this big
// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			// add C for door
// 			if (ft_strchr("1", data->map[y][x]))
// 				color_sqr(data, x, y, 0x0);
// 			else if (ft_strchr("0CNSWE", data->map[y][x]))
// 				color_sqr(data, x, y, 0xd0d0d0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	// put_rays(data, (double)CELL_SIZE / data->cell_size);
	
// 	mlx_put_image_to_window(data->mlx->mlx,
// 		data->mlx->win, data->mlx->img, 0, 0);
// 	mlx_put_image_to_window(g->mlx, g->win.img, g->frame.img, 0, 0);
// 	// mlx_destroy_image(g->mlx, g->frame.img);
// }
// void	put_map(t_data *data)
// {
// 	int	x;
// 	int	y;
	
// 	if (data->keystate->space)
// 		data->cell_size = WIN_W / 40; // how big the map will expand
// 	else
// 		data->cell_size = 10; // else map will be this big
// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			// add C for door
// 			if (ft_strchr3(data->map[y][x], "1"))
// 				color_sqr(data, x, y, 0x0);
// 			else if (ft_strchr3(data->map[y][x], "0"))
// 				color_sqr(data, x, y, 0xd0d0d0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	// put_rays(data, (double)CELL_SIZE / data->cell_size);
// 	mlx_put_mlx_to_window(data->mlx->mlx,
// 		data->mlx->win, data->mlx->img, 0, 0);
// }

// void drawing(t_data *data)
// {
// 	player_movement(data->game); // player movement
// 	// ft_color_win(data, data->mlx, 0); // colours green for the whole map
// 	raycast(data, data->game); // cast rays
// 	// put_map(data); // puts minimap
// 	// mlx_put_image_to_window(data->mlx->mlx,
// 	// 	data->mlx->win, data->mlx->img, 0, 0);
// 	// mlx_put_image_to_window(data->game->mlx, data->game->win.img, data->game->frame.img, 0, 0);
// 	// print_img(data); // still testing
// }

