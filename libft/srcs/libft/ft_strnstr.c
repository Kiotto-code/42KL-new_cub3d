/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:04:14 by yichan            #+#    #+#             */
/*   Updated: 2022/07/06 12:09:31 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (j < len && haystack[j])
	{
		i = 0;
		while (needle[i] == haystack[i + j] && i + j < len)
		{
			if (!needle[i +1])
				return ((char *)haystack + j);
			i++;
		}
		j++;
	}
	return (NULL);
}
