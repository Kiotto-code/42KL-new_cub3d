/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:14 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 10:44:20 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*skip_spaces(char **file)
{
	size_t	end;

	end = 0;
	while (ft_isspace(**file))
		(*file)++;
	while (!ft_isspace((*file)[end]))
		end++;
	return (ft_substr(*file, 0, end));
}

static bool	is_valid_colour(char *colour_str, char **channels)
{
	size_t	i;
	size_t	channel_count;

	i = 0;
	channel_count = ft_arrlen(channels);
	if (channel_count != 3 || getncount(colour_str, ',') > 2)
		return (false);
	while (colour_str[i])
	{
		if (!ft_isdigit(colour_str[i]) && colour_str[i] != ',')
			return (false);
		i++;
	}
	return (true);
}

/**
 * Extracting the string for the colour of the ceiling or the floor
 * and converting it to a usable integer.
 * @param colour_str example: "220,100,0"
 */
static void	extract_colour(t_data *data, char *colour_str, t_colour *colour)
{
	int		i;
	int		j;
	int		colour_int;
	char	**channels;

	i = 2;
	j = 0;
	channels = ft_split(colour_str, ',');
	if (!is_valid_colour(colour_str, channels))
		errno(COLOUR, "", data);
	colour->a = 0;
	while (i >= 0)
	{
		colour_int = ft_atoi(channels[i]);
		if (colour_int < 0 || colour_int > 255)
			errno(COLOUR, "", data);
		colour->bgra[j] = colour_int;
		i--;
		j++;
	}
	free_2d(channels);
}

static void	element_rec(t_data *data, char *word, char *path)
{
	if (!data->ceiling && ft_strcmp(word, "C") == 0)
	{
		data->ceiling = malloc(sizeof(t_colour));
		extract_colour(data, path, data->ceiling);
	}
	else if (!data->floor && ft_strcmp(word, "F") == 0)
	{
		data->floor = malloc(sizeof(t_colour));
		extract_colour(data, path, data->floor);
	}
	else if (!data->texture[NORTH].img->ptr && ft_strcmp(word, "NO") == 0)
		init_texture(data, &data->texture[NORTH], path);
	else if (!data->texture[SOUTH].img->ptr && ft_strcmp(word, "SO") == 0)
		init_texture(data, &data->texture[SOUTH], path);
	else if (!data->texture[WEST].img->ptr && ft_strcmp(word, "WE") == 0)
		init_texture(data, &data->texture[WEST], path);
	else if (!data->texture[EAST].img->ptr && ft_strcmp(word, "EA") == 0)
		init_texture(data, &data->texture[EAST], path);
	else
		errno(INV_CHAR, "", data);
}

void	element_check(t_data *data, char **file)
{
	size_t	len;
	char	*word;
	char	*path;
	size_t	i;

	i = 0;
	while (i < 6 && *file && **file)
	{
		word = skip_spaces(file);
		len = ft_strlen(word);
		if (len < 1 || len > 2)
			errno(INV_CHAR, "", data);
		*file += len;
		path = skip_spaces(file);
		element_rec(data, word, path);
		*file += ft_strlen(path);
		free(word);
		free(path);
		i++;
	}
}
