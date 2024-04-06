/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:29:31 by yichan            #+#    #+#             */
/*   Updated: 2022/10/10 16:48:27 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nodes;
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		nodes = ft_lstnew(f(lst->content));
		if (!nodes)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, nodes);
		lst = lst->next;
	}
	return (new_lst);
}
