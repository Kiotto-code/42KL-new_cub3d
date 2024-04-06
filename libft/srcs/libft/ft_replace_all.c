/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:48:29 by yichan            #+#    #+#             */
/*   Updated: 2024/03/14 16:27:16 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_replace_all(char **s, const char *old, const char *new, int start)
{
	int	i;

	if (start < 0)
		return (EXIT_FAILURE);
	i = start;
	while (i < (int)ft_strlen(*s) && i != -1)
	{
		i = ft_replace(s, old, new, i);
	}
	if (i > start)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
