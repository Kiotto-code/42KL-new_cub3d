/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:46:04 by yichan            #+#    #+#             */
/*   Updated: 2023/04/24 22:07:45 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
	{
		new->prev = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
	}
	else
		*lst = new;
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*temp;

// 	temp = *lst;
// 	if (lst == NULL || new == NULL)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	while (temp->next != NULL)
// 	{
// 		temp = temp->next;
// 	}
// 	temp->next = new;
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list *ptr;

// 	ptr = *lst;
// 	if (ptr)
// 	{
// 		new->prev = ft_lstlast(ptr);
// 		ft_lstlast(ptr)->next = new;
// 	}
// 	else
// 		*lst = new;
// }