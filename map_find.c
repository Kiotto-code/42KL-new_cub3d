/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_reading.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:32:35 by yichan            #+#    #+#             */
/*   Updated: 2024/03/06 15:18:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	get_player_view(t_book *record, t_map *map_table)
{
	int i;
	int j;
	char **map;
	char *str;

	i = 0;
	map = record->map;
	while (map[i])
	{
		j = 0;
		str = map[i];
		while (str[j])
		{
			if (ft_strchr("NSWE", str[j]))
			{
				map_table->pv = str[j];
				map_table->px = j;
				map_table->py = i;
				return (SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (FAIL);
}


int file_data_recording(t_book *record)
{
	char **elem;
	char **split;
	t_map *map;
	int i;

	i = 0;
	map = record->map_table;
	elem = record->elem_record;
	while (*elem)
	{
		ft_replace_all(&(*elem), "\t", " ", 0);
		split = ft_split(*elem, ' ');
		if (ft_arrlen(split) != 2)
			return (FAIL);
		map->meta_data[END] = NULL;
		if (ft_strcmp(split[0], "NO") == SUCCESS)
			map->meta_data[NO] = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "SO") == SUCCESS)
			map->meta_data[SO] = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "WE") == SUCCESS)
			map->meta_data[WE] = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "EA") == SUCCESS)
			map->meta_data[EA] = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "F") == SUCCESS)
			map->meta_data[F] = ft_strdup(split[1]);
		else if (ft_strcmp(split[0], "C") == SUCCESS)
			map->meta_data[C] = ft_strdup(split[1]);
		else
			return (FAIL);
		free(split);
		elem++;
	}
	i = 0;
	// while (i < 6)
	// {
	// 	if (map->meta_data[i] == NULL)
	// 		return (FAIL);
	// 	printf("meta_data[%d] : %s\n", i, map->meta_data[i]);
	// 	i++;
	// }
	ft_print_arr(map->meta_data, "meta_data");
	get_colors(record->map_table);
	get_player_view(record, record->map_table);
	return (SUCCESS);
}

int	check_map_holes(char **map)
{
	int i;
	int j;
	char *str;

	i = 0;
	while (map[i])
	{
		j = 0;
		str = map[i];
		while (str[j])
		{
			if (ft_strchr("0NWSE", str[j]))
			{
				if (map[i+1] && map[i+1][j] == ' ')
					return (FAIL);
				if (map[i-1] && map[i-1][j] == ' ')
					return (FAIL);
				if (map[i][j+1] == ' ')
					return (FAIL);
				if (map[i][j-1] == ' ')
					return (FAIL);
				
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}


int	file_data_reading(t_book *record)
{
	const char	*order[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	char		**content;
	int			i;

	content = record->file_content;
	i = 0;
	while (content[i])
	{
		if (content[i][0] == '1' || content[i][0] == ' ')
			break ;
		i++;
		if (order[i] == NULL)
			break ;
	}
	record->elem_record = ft_subarr(content, 0, i-1);
	ft_print_arr(record->elem_record, "record->elem_record");
	content += i;
	record->map = ft_duparr(content);
	ft_print_arr(record->map, "record->map");
	if (check_map_holes(record->map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
