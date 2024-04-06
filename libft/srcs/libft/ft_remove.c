/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 01:57:51 by yichan            #+#    #+#             */
/*   Updated: 2024/03/29 15:31:24 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

char	*ft_remove(char *input, char c)
{
	int		i;
	int		j;
	int		remain_size;
	char	*ret;

	remain_size = ft_strlen(input) - count_words(input, c);
	printf("remain_size : %d\n", remain_size);
	ret = ft_calloc(sizeof(char), (remain_size +1));
	if (!ret)
		return (NULL);
	i = -1;
	j = -1;
	while (input[++i])
	{
		if (input[i] != c)
			ret[++j] = input[i];
	}
	printf("ret : %s\n", ret);
	ft_free(input);
	return (ret);
}
