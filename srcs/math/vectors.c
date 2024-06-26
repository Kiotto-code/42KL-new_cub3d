/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:39:01 by yichan            #+#    #+#             */
/*   Updated: 2024/04/02 00:55:50 by etlaw            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

t_vector	vector_substr(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = first.x - second.x;
	vector.y = first.y - second.y;
	return (vector);
}

t_vector	vector_add(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = first.x + second.x;
	vector.y = first.y + second.y;
	return (vector);
}

t_vector	vector_multpl(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = (first.x * second.x) - (first.y * second.y);
	vector.y = 2 * (first.x * second.y);
	return (vector);
}

t_vector	rotatevector(t_vector vct, double angle)
{
	t_vector	tmp;

	tmp.x = vct.x;
	tmp.y = vct.y;
	vct.x = (tmp.x * cos(angle * M_PI / 180))
		- (tmp.y * sin(angle * M_PI / 180));
	vct.y = (tmp.x * sin(angle * M_PI / 180))
		+ (tmp.y * cos(angle * M_PI / 180));
	return (vct);
}

double	vec_dot(t_vector one, t_vector two)
{
	t_vector	tmp1;
	t_vector	tmp2;

	tmp1 = normalize_vec(one);
	tmp2 = normalize_vec(two);
	return ((tmp1.x * tmp2.x) + (tmp1.y * tmp2.y));
}
