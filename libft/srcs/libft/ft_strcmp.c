/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:31:47 by yichan            #+#    #+#             */
/*   Updated: 2023/07/02 16:10:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return 0 if the string is same, Non-ZEro if the diff
 * 
 * @param s1 
 * @param s2 
 * @return int 
 */

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	it;

	it = 0;
	while (s1[it] && s2[it] && (s1[it] == s2[it]))
		it++;
	return ((unsigned char)s1[it] - (unsigned char)s2[it]);
}
