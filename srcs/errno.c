/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:30 by yichan            #+#    #+#             */
/*   Updated: 2024/03/29 15:23:50 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/cub3d.h"

/** 
 * @brief Writes an error message to STDERR.
 * You can add an additional message, otherwise add "" as 2nd argument.
 * @param nbr Signifies with error message from the array to be used.
 * @param msg additional message after the error message.
 */
void	errno(int8_t nbr, char *msg, t_data *data)
{
	static const char	*errors[] = {
		"Creating window failed",
		"Too many arguments",
		"Failed reading the file",
		"Wrong colour channel given in input file. Ex: C 220,100,0",
		"You need to give a .cub file as argument",
		"Contains invalid characters",
		"Wrong file extension",
		"The map must be closed/surrounded by walls",
		"Invalid texture: ",
		"Creating image failed: ",
		"Too many players",
		"Map doesn't contain a player"
	};

	ft_printf("Error\n%s%s", errors[nbr], msg);
	free_data(data);
	exit(nbr);
}
