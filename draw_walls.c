/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:45:47 by absalhi           #+#    #+#             */
/*   Updated: 2024/03/24 05:33:17 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

unsigned int	get_textcolor(t_game *g, int type, t_iterators text_offset)
{
	int	ind;

	ind = (text_offset.i * TILE_SIZE) + text_offset.j;
	return (((unsigned int *) g->textures[type].addr)[ind]);
}

void	put_stripe(t_game *g, t_iterators it, t_iterators text_offset, int i)
{
	unsigned int	textcolor;

	if (g->rays[it.i].vertical_hit)
	{
		if (g->rays[it.i].horz_inters.x > g->player.pos.x)
			textcolor = get_textcolor(g, TEXT_E, text_offset);
		else
			textcolor = get_textcolor(g, TEXT_W, text_offset);
	}
	else
	{
		if (g->rays[it.i].vert_inters.y > g->player.pos.y)
			textcolor = get_textcolor(g, TEXT_S, text_offset);
		else
			textcolor = get_textcolor(g, TEXT_N, text_offset);
	}
	cub_pixel_put(g, it.i * g->constants.scale, i, textcolor);
}

void	draw_stripe(t_game *g, t_iterators it, int wall_top, int wall_bottom)
{
	t_iterators	text_offset;
	float		d;
	int			i;

	if (g->rays[it.i].vertical_hit)
		text_offset.j = (int) g->rays[it.i].vert_inters.y;
	else
		text_offset.j = (int) g->rays[it.i].horz_inters.x;
	d = TILE_SIZE / g->rays[it.i].proj_h;
	i = wall_top;
	while (i < wall_bottom)
	{
		text_offset.i = (i + (int) g->rays[it.i].proj_h / 2
				- g->constants.half_win_height) * d;
		put_stripe(g, it, text_offset, i);
		i++;
	}
	// printf("i = %d\n", i);
}

// typedef struct s_draw_walls
// {
// 	int			i;
// 	int			wall_top_pixel;
// 	int			wall_bottom_pixel;
// 	float		depth;
// }	t_draw_walls;

// void	draw_walls(t_game *g, int it, float ray_angle)
// {
// 	t_draw_walls	s;

// 	s.depth = g->rays[it.i].depth * (float) cos(g->player.angle - ray_angle);
// 	g->rays[it.i].proj_h = (TILE_SIZE / s.depth) * g->constants.screen_dist;
// 	s.wall_top_pixel
// 		= g->constants.half_win_height - (int) g->rays[it.i].proj_h / 2;
// 	if (s.wall_top_pixel < 0)
// 		s.wall_top_pixel = 0;
// 	s.wall_bottom_pixel
// 		= g->constants.half_win_height + (int) g->rays[it.i].proj_h / 2;
// 	if (s.wall_bottom_pixel > WIN_H)
// 		s.wall_bottom_pixel = WIN_H;
// 	s.i = -1;
// 	while (++s.i < s.wall_top_pixel)
// 		cub_pixel_put(g,
// 			it.i * g->constants.scale, s.i, create_rgb(g->assets.ceiling));
// 	// draw_stripe(g, it, s.wall_top_pixel, s.wall_bottom_pixel);
// 	s.i = s.wall_bottom_pixel - 1;
// 	while (++s.i < WIN_H)
// 		cub_pixel_put(g,
// 			it.i * g->constants.scale, s.i, create_rgb(g->assets.floor));
// }



void	draw_walls(t_game *g, t_iterators it, float ray_angle)
{
	t_draw_walls	s;

	s.depth = g->rays[it.i].depth * (float) cos(g->player.angle - ray_angle);
	g->rays[it.i].proj_h = (TILE_SIZE / s.depth) * g->constants.screen_dist;
	s.wall_top_pixel
		= g->constants.half_win_height - (int) g->rays[it.i].proj_h / 2;
	if (s.wall_top_pixel < 0)
		s.wall_top_pixel = 0;
	s.wall_bottom_pixel
		= g->constants.half_win_height + (int) g->rays[it.i].proj_h / 2;
	if (s.wall_bottom_pixel > WIN_H)
		s.wall_bottom_pixel = WIN_H;
	s.i = -1;
	while (++s.i < s.wall_top_pixel)
		cub_pixel_put(g,
			it.i * g->constants.scale, s.i, create_rgb(g->assets.ceiling));
	draw_stripe(g, it, s.wall_top_pixel, s.wall_bottom_pixel);
	s.i = s.wall_bottom_pixel - 1;
	while (++s.i < WIN_H)
		cub_pixel_put(g,
			it.i * g->constants.scale, s.i, create_rgb(g->assets.floor));
}



// void	draw_walls(t_game *g, int i, float ray_angle)
// {
// 	t_draw_walls	s;
// 	t_iterators		it;

// 	// printf("dg->rays[i].depth = %f\n", cos(g->player.angle - ray_angle));
// 	// printf("dg->rays[i].depth = %p\n", &g->rays[0]);
// 	// printf("dg->rays[i].depth = %f\n", g->rays[0].depth);
// 	// pause();
// 	s.depth = g->rays[i].depth * (float) cos(g->player.angle - ray_angle);
// 	g->rays[i].proj_h = (TILE_SIZE / s.depth) * g->constants.screen_dist;
// 	s.wall_top_pixel
// 		= g->constants.half_win_height - (int) g->rays[i].proj_h / 2;
// 	if (s.wall_top_pixel < 0)
// 		s.wall_top_pixel = 0;
// 	s.wall_bottom_pixel
// 		= g->constants.half_win_height + (int) g->rays[i].proj_h / 2;
// 	// printf("s.wall_bottom_pixel = %d\n", s.wall_bottom_pixel);
// 	// pause();
// 	if (s.wall_bottom_pixel > WIN_H)
// 		s.wall_bottom_pixel = WIN_H;
// 	s.i = -1;
// 	// printf("s.g->winwidth = %d\n", g->win.width);
// 	// printf("s.g->winheight = %d\n", g->win.height);
// 	// pause();
// 	while (++s.i < s.wall_top_pixel)
// 		cub_pixel_put(g,
// 			i * g->constants.scale, s.i, create_rgb(g->assets.ceiling));
// 	it.i = i;
// 	draw_stripe(g, it, s.wall_top_pixel, s.wall_bottom_pixel);
// 	// printf("s.wall_bottom_pixel = %d\n", s.wall_bottom_pixel);
// 	// printf("s.wall_top_pixel = %d\n", s.wall_top_pixel);
// 	// pause();
// 	s.i = s.wall_bottom_pixel - 1;
// 	while (++s.i < WIN_H)
// 		cub_pixel_put(g,
// 			i * g->constants.scale, s.i, create_rgb(g->assets.floor));
// }


// unsigned int	get_textcolor(t_game *g, int type, t_iterators text_offset)
// {
// 	int	ind;

// 	ind = (text_offset.i * TILE_SIZE) + text_offset.j;
// 	return (((unsigned int *) g->textures[type].addr)[ind]);
// }

// void	put_stripe(t_game *g, t_iterators it, t_iterators text_offset, int i)
// {
// 	unsigned int	textcolor;

// 	if (g->rays[it.i].vertical_hit)
// 	{
// 		if (g->rays[it.i].horz_inters.x > g->player.pos.x)
// 			textcolor = get_textcolor(g, TEXT_E, text_offset);
// 		else
// 			textcolor = get_textcolor(g, TEXT_W, text_offset);
// 	}
// 	else
// 	{
// 		if (g->rays[it.i].vert_inters.y > g->player.pos.y)
// 			textcolor = get_textcolor(g, TEXT_S, text_offset);
// 		else
// 			textcolor = get_textcolor(g, TEXT_N, text_offset);
// 	}
// 	cub_pixel_put(g, it.i * g->constants.scale, i, textcolor);
// }

// void	draw_stripe(t_game *g, t_iterators it, int wall_top, int wall_bottom)
// {
// 	t_iterators	text_offset;
// 	float		d;
// 	int			i;

// 	if (g->rays[it.i].vertical_hit)
// 		text_offset.j = (int) g->rays[it.i].vert_inters.y;
// 	else
// 		text_offset.j = (int) g->rays[it.i].horz_inters.x;
// 	d = TILE_SIZE / g->rays[it.i].proj_h;
// 	i = wall_top;
// 	while (i < wall_bottom)
// 	{
// 		text_offset.i = (i + (int) g->rays[it.i].proj_h / 2
// 				- g->constants.half_win_height) * d;
// 		put_stripe(g, it, text_offset, i);
// 		i++;
// 	}
// }

// void	draw_walls(t_game *g, int it, float ray_angle)
// {
// 	t_draw_walls	s;
// 	t_iterators		iter;

// 	s.depth = g->rays[it].depth * (float) cos(g->player.angle - ray_angle);
// 	g->rays[it].proj_h = (TILE_SIZE / s.depth) * g->constants.screen_dist;
// 	s.wall_top_pixel
// 		= g->constants.half_win_height - (int) g->rays[it].proj_h / 2;
// 	if (s.wall_top_pixel < 0)
// 		s.wall_top_pixel = 0;
// 	s.wall_bottom_pixel
// 		= g->constants.half_win_height + (int) g->rays[it].proj_h / 2;
// 	if (s.wall_bottom_pixel > WIN_H)
// 		s.wall_bottom_pixel = WIN_H;
// 	s.i = -1;
// 	while (++s.i < s.wall_top_pixel)
// 		cub_pixel_put(g,
// 			it * g->constants.scale, s.i, create_rgb(g->assets.ceiling));
// 	iter.i = it;
// 	draw_stripe(g, iter, s.wall_top_pixel, s.wall_bottom_pixel);
// 	s.i = s.wall_bottom_pixel - 1;
// 	while (++s.i < WIN_H)
// 		cub_pixel_put(g,
// 			it * g->constants.scale, s.i, create_rgb(g->assets.floor));
// }
