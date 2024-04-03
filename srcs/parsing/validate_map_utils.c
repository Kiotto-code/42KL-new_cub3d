/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:22 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 10:44:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_str(char *str, size_t start, size_t end, char c)
{
	size_t	i;

	i = start;
	while (i < end)
		str[i++] = c;
	str[i] = '\0';
}

/**
 * @brief counting newlines at the end of the file to adjust the mapheight
 * in largest_row()
 */
int	count_newlines_end(char *file)
{
	int		i;
	size_t	count;

	count = 0;
	i = ft_strlen(file);
	while (i >= 0 && file[i] == '\n')
	{
		count++;
		i--;
	}
	return (count);
}

int	count_newlines_start(char *file)
{
	size_t	count;

	count = 0;
	while (*file && ft_isspace(*file))
	{
		if (*file == '\n')
			count++;
		file++;
	}
	return (count);
}
