/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:45:05 by yichan            #+#    #+#             */
/*   Updated: 2024/03/29 15:31:07 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_duparr(char **arr)
{
	char	**ret;
	int		arr_len;

	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
	ret = ft_calloc(sizeof(char *), (arr_len + 1));
	ret[arr_len] = 0;
	while (--arr_len >= 0 && arr[arr_len])
	{
		ret[arr_len] = ft_strdup(arr[arr_len]);
	}
	return (ret);
}
