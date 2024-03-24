/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:20:08 by absalhi           #+#    #+#             */
/*   Updated: 2024/03/23 20:35:30 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	cub_load_textures(t_game *g)
{
	g->textures[TEXT_N].addr = mlx_get_data_addr(g->textures[TEXT_N].img,
			&g->textures[TEXT_N].bits_per_pixel, &g->textures[TEXT_N].line_length,
			&g->textures[TEXT_N].endian);
	if (!g->textures[TEXT_N].addr)
	{
		printf("Failed to get data addr of north xpm check 2.\n");
		return (ft_error("Failed to get data addr of north xpm.", 1), FAIL);
	}
	g->textures[TEXT_S].addr = mlx_get_data_addr(g->textures[TEXT_S].img,
			&g->textures[TEXT_S].bits_per_pixel, &g->textures[TEXT_S].line_length,
			&g->textures[TEXT_S].endian);
	if (!g->textures[TEXT_S].addr)
		return (ft_error("Failed to get data addr of south xpm.", 1), FAIL);
	g->textures[TEXT_E].addr = mlx_get_data_addr(g->textures[TEXT_E].img,
			&g->textures[TEXT_E].bits_per_pixel, &g->textures[TEXT_E].line_length,
			&g->textures[TEXT_E].endian);
	if (!g->textures[TEXT_E].addr)
		return (ft_error("Failed to get data addr of east xpm.", 1), FAIL);
	g->textures[TEXT_W].addr = mlx_get_data_addr(g->textures[TEXT_W].img,
			&g->textures[TEXT_W].bits_per_pixel, &g->textures[TEXT_W].line_length,
			&g->textures[TEXT_W].endian);
	if (!g->textures[TEXT_W].addr)
		return (ft_error("Failed to get data addr of west xpm.", 1), FAIL);
	return (RETURN_SUCCESS);
}

int	cub_init_textures(t_game *g)
{
	t_iterators	it;

	g->textures[TEXT_N].img = mlx_xpm_file_to_image(g->mlx, g->assets.north,
			&it.i, &it.j);
	if (!g->textures[TEXT_N].img)
	{
		printf("g->assets.north: %s\n", g->assets.north);
		printf("Failed to get data addr of north xpm check 1.\n");
		return (ft_error("Failed to get data addr of north xpm.", 1), FAIL);
	}
	g->textures[TEXT_S].img = mlx_xpm_file_to_image(g->mlx, g->assets.south,
			&it.i, &it.j);
	if (!g->textures[TEXT_S].img)
		return (ft_error("Failed to get data addr of south xpm.", 1), FAIL);
	g->textures[TEXT_E].img = mlx_xpm_file_to_image(g->mlx, g->assets.east,
			&it.i, &it.j);
	if (!g->textures[TEXT_E].img)
		return (ft_error("Failed to get data addr of east xpm.", 1), FAIL);
	g->textures[TEXT_W].img = mlx_xpm_file_to_image(g->mlx, g->assets.west,
			&it.i, &it.j);
	if (!g->textures[TEXT_W].img)
		return (ft_error("Failed to get data addr of west xpm.", 1), FAIL);
	cub_load_textures(g);
	return (RETURN_SUCCESS);
}

int	cub_init(t_game *g)
{
	const t_map *map = &g->map;
	
	g->assets.north = map->meta_data[TEXT_N];
	g->assets.south = map->meta_data[TEXT_S];
	g->assets.east = map->meta_data[TEXT_E];
	g->assets.west = map->meta_data[TEXT_W];
	// g->textures[TEXT_N] = map->meta_data[TEXT_N];
	if (cub_init_textures(g))
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}
