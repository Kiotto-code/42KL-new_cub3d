/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:56:26 by yichan            #+#    #+#             */
/*   Updated: 2023/01/11 18:41:54 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stk	*ft_lstnew2(int content)
{
	t_stk	*node;

	node = malloc(sizeof(t_stk));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->index = 0;
	return (node);
}
