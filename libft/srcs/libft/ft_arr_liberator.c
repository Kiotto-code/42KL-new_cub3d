/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_liberator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:38:33 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 17:54:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	array_liberator(char **array)
{
	int	it;

	it = 0;
	while (array[it])
	{
		ft_free(array[it]);
		array[it] = NULL;
		it++;
	}
	ft_free(array);
	array = NULL;
}
