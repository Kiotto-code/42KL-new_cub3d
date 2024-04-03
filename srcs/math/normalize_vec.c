/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:38:54 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 10:41:10 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	normalize_vec(t_vector vec)
{
	t_vector	out;
	double		length;

	length = sqrt(vec.x * vec.x + vec.y * vec.y);
	out.x = vec.x / length;
	out.y = vec.y / length;
	return (out);
}
