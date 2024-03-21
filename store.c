/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:49:53 by yichan            #+#    #+#             */
/*   Updated: 2024/03/21 15:37:02 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	get_colors(t_map *map)
{
	char	**c;
	char	**f;
	int		i;

	i = 0;
	c = ft_split(map->meta_data[C], ',');
	f = ft_split(map->meta_data[F], ',');
	if (ft_arrlen(c) != 3 || ft_arrlen(f) != 3)
		return (0);
	map->f_color[0] = ft_atoi(f[0]);
	map->f_color[1] = ft_atoi(f[1]);
	map->f_color[2] = ft_atoi(f[2]);
	map->c_color[0] = ft_atoi(c[0]);
	map->c_color[1] = ft_atoi(c[1]);
	map->c_color[2] = ft_atoi(c[2]);	
	return (1);
}


int	store(t_book *record)
{
	t_map	*map;

	map = record->map_table;
	map->arr = record->map;
	// map->map_name = record->file;
	
	if (!get_colors(map))
		return (0);

	return (1);
}
