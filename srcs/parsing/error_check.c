/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:06 by yichan            #+#    #+#             */
/*   Updated: 2024/03/30 20:06:17 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/cub3d.h"

static void	extension_check(t_data *data, char *map_name, char *ext)
{
	size_t	len;

	len = ft_strlen(map_name);
	while (len > 0)
	{
		if (map_name[len] == '.')
			break ;
		len--;
	}
	if (ft_strcmp(&map_name[len], ext) != 0)
		return (errno(INV_EXT, "", data));
}

void	error_check(t_data *data, int argc, char **argv)
{
	int	fd;
	char	*file;
	char	*tempfile;

	if (argc > 2)
		errno(ARGS, "", data);
	if (argc <= 1)
		errno(NO_CUB, "", data);
	extension_check(data, argv[1], ".cub");
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		errno(READ_FAIL, "", data);
	file = read_file(fd);
	tempfile = file;
	element_check(data, &file);
	// ft_printf("file checked: %s\n\n", file);
	// pause();
	extract_map(data, file);
	free(tempfile);
}
