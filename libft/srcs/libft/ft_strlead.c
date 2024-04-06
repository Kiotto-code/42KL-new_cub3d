/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:58:05 by yichan            #+#    #+#             */
/*   Updated: 2024/03/14 15:26:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check if s2 is head of string s1;

int	ft_strlead(const char *s1, const char *s2)
{
	size_t	it;

	it = 0;
	while (s1[it] && (s1[it] == s2[it] && s2[it]))
		it++;
	if (s2[it] == '\0')
		return (1);
	return (0);
}
// printf(BLUE"success\n"RESET);
