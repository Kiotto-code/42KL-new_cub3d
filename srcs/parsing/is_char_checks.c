/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:10 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 10:41:47 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_space_or_1(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
		c == '\v' || c == '\f' || c == '\r' || c == '1')
		return (true);
	return (false);
}

bool	is_valid_char(char c)
{
	if (ft_isspace(c) || c == '0' || c == '1' || c == 'N' || \
		c == 'E' || c == 'O' || c == 'W' || c == 'C')
		return (true);
	return (false);
}

bool	is_player(t_data *data, t_player *player, int x, int y)
{
	if (data->map[y][x] != 'N' && data->map[y][x] != 'E' \
	&& data->map[y][x] != 'S' && data->map[y][x] != 'W')
		return (false);
	player->pos.x = x * TILE + (TILE / 2);
	player->pos.y = y * TILE + (TILE / 2);
	if (data->map[y][x] == 'N')
		player->dir.y = -1 * TILE / 4;
	if (data->map[y][x] == 'S')
		player->dir.y = TILE / 4;
	if (data->map[y][x] == 'E')
		player->dir.x = TILE / 4;
	if (data->map[y][x] == 'W')
		player->dir.x = -1 * TILE / 4;
	data->map[y][x] = '0';
	return (true);
}
