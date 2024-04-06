/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:53:41 by yichan            #+#    #+#             */
/*   Updated: 2023/07/25 23:42:34 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*temp;
// 	unsigned int	i;

// 	if (!dest || !src)
// 		return (NULL);
// 	i = 0;
// 	temp = (unsigned char *)src;
// 	if (dest < src)
// 	{
// 		while (i < n && temp[i])
// 		{
// 			((unsigned char *)dest)[i] = temp[i];
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (n-- > 0)
// 			((unsigned char *)dest)[n] = temp[n];
// 	}
// 	return (dest);
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
