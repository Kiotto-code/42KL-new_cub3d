/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getncount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:38:24 by yichan            #+#    #+#             */
/*   Updated: 2024/03/29 15:38:29 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	getncount(char *str, uint8_t n)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == n)
			count++;
		str++;
	}
	return (count);
}
