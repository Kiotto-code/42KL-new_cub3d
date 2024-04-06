/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:40:38 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 10:23:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_calloc(size_t count)
// {
// 	void			*ptr;

// 	if (count >= SIZE_MAX)
// 		return (NULL);
// 	if (count == 0)
// 		count = 1;
// 	ptr = malloc(count);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero (ptr, count);
// 	return (ptr);
// }

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// void*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;

// 	if (count >= INT_MAX || size >= INT_MAX)
// 		return (NULL);
// 	ptr = (void*)malloc(count * size);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, count);
// 	return (ptr);
// }