/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:18 by yichan            #+#    #+#             */
/*   Updated: 2024/04/07 22:32:20 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Reads the map into one big ass string directly with the read 
 * function instead of GNL to avoid memory fuckery and having it 
 * initialised instead of reading repeatedly is more efficient.
 * Later on store it in a 2D array for easy error checking
 * and data checking during the game loop. 
 */
char	*read_file(int fd)
{
	char	*line;
	char	*tmp;

	line = ft_calloc(1, 1);
	while (true)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		line = ft_strjoinf(line, tmp);
		free(tmp);
	}
	line = ft_strjoinf(line, "\n");
	return (line);
}
