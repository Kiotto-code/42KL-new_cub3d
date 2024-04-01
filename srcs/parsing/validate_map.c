/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:26 by yichan            #+#    #+#             */
/*   Updated: 2024/03/30 22:21:42 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/cub3d.h"

static void	largest_row(t_data *data, char *file)
{
	size_t	row_len;
	size_t	largest_row;

	row_len = 0;
	largest_row = 0;
	while (*file)
	{
		row_len = ft_strclen(file, '\n');
		if (row_len > largest_row)
			largest_row = row_len;
		file += (row_len + 1);
		data->map_height++;
	}
	data->map_width = largest_row;
}

static bool	around_space_valid(t_data *data, char **map, int x, int y)
{
	if (ft_isspace(map[y][x]))
	{
		if ((y != data->map_height - 1 && !is_space_or_1(map[y + 1][x])) || \
		(y != 0 && !is_space_or_1(map[y - 1][x])) || \
		(x != 0 && !is_space_or_1(map[y][x - 1])) || \
		(x != data->map_width - 1 && !is_space_or_1(map[y][x + 1])))
			return (false);
	}
	return (true);
}

/**
 * If there is anything but a 1 or space neighbouring a space, the map is not
 * enclosed and returns an error. Also checks for invalid characters in the map.
 * @param data 
 * @param map 
 */
static int	mapcheck(t_data *data, char **map)
{
	int	x;
	int	y;
	int	player;

	x = 0;
	y = 0;
	player = 0;
	while (y < data->map_height && map[y])
	{
		while (x < data->map_width && map[y][x])
		{
			if (!is_valid_char(map[y][x]))
			{
				printf("x: %d, y: %d\n", x, y);
				printf("map[y][x]: |%d|\n", map[y][x]);
				errno(INV_CHAR, "", data);
			}
			if (!around_space_valid(data, map, x, y))
				errno(INV_MAP, "", data);
			if (is_player(data, &data->player, x, y))
				player++;
			if (player > 1)
				errno(PLAYERS, "", data);
			x++;
		}
		x = 0;
		y++;
	}
	return (player);
}

// void	get_map_w_h(t_data *data)
// {
// 	int		i;
// 	char	**tab;

// 	i = 0;
// 	tab = data->map;
// 	data->map_height = 0;
// 	while (tab[i])
// 	{
// 		if ((int)ft_strlen(tab[i]) > data->map_width)
// 			data->map_width = ft_strlen(tab[i]);
// 		// ft_find_player(tab[i], map);
// 		data->map_height++;
// 		i++;
// 	}
// 	// data->map_height --;
// 	// data->map_width --;
// 	// printf("map->map_h = %d\n", map->map_h);
// 	// map->map_vh = map->map_h * CELL_SIZE;
// 	// map->map_vw = map->map_w * CELL_SIZE;
// }

// void	extract_map(t_data *data, char *file)
// {
// 	char		**content;
// 	int			player;
// 	int			i;
	
// 	ft_printf(RED"file: %s\n"RESET, file);
// 	content = ft_split(file, '\n');
// 	// ft_print_arr(content, "content");
// 	// pause();
// 	i = 0;
// 	while (content[i])
// 	{
// 		if (content[i][0] == '1' || content[i][0] == ' ')
// 			break ;
// 	}
// 	// content += i;
// 	data->map = ft_duparr(content +i);
// 	free_2d(content);
// 	get_map_w_h(data);
// 	ft_print_arr(data->map, "data->map");
// 	// pause();
// 	player = mapcheck(data, data->map);
// 	if (player < 1)
// 		errno(NOPLAYER, "", data);
// }
void	extract_map(t_data *data, char *file)
{
	size_t	i;
	size_t	row_length;
	int	player;

	i = 0;
	file += count_newlines_start(file);
	largest_row(data, file);
	data->map_height -= count_newlines_end(file);
	if (data->map_height < 3 || data->map_width < 3)
		errno(READ_FAIL, "", data);
	data->map = ft_calloc(data->map_height, sizeof(char *) + 1);
	while (i < (size_t)data->map_height)
	{
		data->map[i] = ft_calloc(data->map_width + 1, sizeof(char));
		row_length = ft_strccpy(data->map[i], file, '\n');
		fill_str(data->map[i], row_length, data->map_width, ' ');
		file += row_length + 1;
		i++;
	}
	player = mapcheck(data, data->map);
	if (player < 1)
		errno(NOPLAYER, "", data);
}

// int	file_data_reading(t_book *record)
// {
// 	const char	*order[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
// 	char		**content;
// 	int			i;

// 	content = record->file_content;
// 	i = 0;
// 	while (content[i])
// 	{
// 		if (content[i][0] == '1' || content[i][0] == ' ')
// 			break ;
// 		i++;
// 		if (order[i] == NULL)
// 			break ;
// 	}
// 	record->elem_record = ft_subarr(content, 0, i-1);
// 	ft_print_arr(record->elem_record, "record->elem_record");
// 	content += i;
// 	record->map = ft_duparr(content);
// 	ft_print_arr(record->map, "record->map");
// 	if (check_map_holes(record->map) == FAIL)
// 	{
// 		printf("MAP HAS HOLES\n");
// 		return (FAIL);
// 	}
// 	return (SUCCESS);
// }
