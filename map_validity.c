/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:49:19 by yichan            #+#    #+#             */
/*   Updated: 2024/03/21 15:03:03 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

//check if the while string made up of only 1
int	all_wall(char *str)
{
	int	status;

	status = SUCCESS;
	while (*str++ && status == SUCCESS)
	{
		// printf(GREEN"mapline here %c\n", *str);
		if (*str == '\0')
			break ;
		// if (*str != '1')
		if (ft_strchr("1 ", *str) == NULL)
		{
			status |= FAIL;
			printf(RED"check: %s;ine break here\n", str);
			break ;	
		}
		// if 
	}
	printf(RED"all_wall STATUS HERE: %s\n"RESET, status ? "FAIL" : "SUCCESS");
	return (status);
}

//ends wall is checking the wall at the first and last square. (tail end)
int	ends_wall(char **map)
{
	int		status;
	char	*mapline;
	int		i;
	int		line_len_diff;

	status = SUCCESS;
	i = 0;
	mapline = map[i++];
	while (mapline && *mapline && status == SUCCESS)
	{
		if (mapline[ft_strlen(mapline) -1] != '1')
			status |= FAIL;
		if (mapline[0] != '1')
			status |= FAIL;
		mapline = map[i++];
	}
	i = 0;
	while(++i < ft_arrlen(map))
	{
		line_len_diff = ft_strlen(map[i]) - ft_strlen(map[i -1]);
		if (line_len_diff > 0 && all_wall(map[i] + (ft_strlen(map[i]) - line_len_diff)) == FAIL)
			return (FAIL);
		line_len_diff = ft_strlen(map[i]) - ft_strlen(map[i +1]);
		if (line_len_diff > 0 && all_wall(map[i] + (ft_strlen(map[i]) - line_len_diff)) == FAIL)
			return (FAIL);
	}
	printf(RED"ends_wall STATUS HERE: %s\n"RESET, status ? "FAIL" : "SUCCESS");
	return (status);
}

int	map_valid_wall_surround(t_book *record)
{
	char	*last_map;
	// int		bottomlen;
	// int		toplen;
	int		i;
	
	if (record->map[0] && all_wall(record->map[0]) == FAIL)
		return (FAIL);
	if (ends_wall(record->map) == FAIL)
		return (FAIL);
	i = 0;
	while (record->map[i])
		i++;
	last_map = record->map[i-1];
	if (last_map && all_wall(last_map) == FAIL)
		return (FAIL);
	// toplen = ft_strlen(record->map[0]);
	// bottomlen = ft_strlen(last_map);
	
	return (SUCCESS);
}

int	map_reading(t_book *record)
{
	int		fd;
	char	*tmp;
	char	*fileline;

	fd = open(record->file, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("failed open file", 2), FAIL);
	fileline = ft_strdup("");
	while (true)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		fileline = ft_strjoinf(fileline, tmp);
		free(tmp);
	}
	record->file_content = ft_split(fileline, '\n');
	if (file_data_reading(record) == FAIL)
	{
		ft_putendl_fd("invalid file sequence format as subject required", 2);
		return (FAIL);
	}
	// file_data_recording(record);
	if (map_valid_wall_surround(record) == FAIL)
		return (ft_putendl_fd("invalid map as not wall surrounded", 2), FAIL);
	return (SUCCESS);
}
