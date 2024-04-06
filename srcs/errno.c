/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:30 by yichan            #+#    #+#             */
/*   Updated: 2024/04/05 21:25:30 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		"Invalid texture",
		"Creating image failed",
		"Too many players",
		"Map doesn't contain a player"
	};

	(void)msg;
	ft_printf("Error: %s\n", errors[nbr]);
	free_data(data);
	exit(nbr);
}
