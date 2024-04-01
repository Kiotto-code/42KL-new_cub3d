/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio_to_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:38:58 by yichan            #+#    #+#             */
/*   Updated: 2024/03/28 16:38:59 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/cub3d.h"

double	ratio_is_actually_distance(t_data *data, double dist, \
		t_vector first, int cond)
{
	if (cond == OUT_BOUNDS)
		dist = A_VERY_VERY_BIG_NUMMER;
	else
	{
		first = vector_substr(data->player.pos, first);
		dist = sqrt(first.x * first.x + first.y * first.y);
	}
	return (dist);
}
