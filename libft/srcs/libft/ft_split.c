/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:34:32 by yichan            #+#    #+#             */
/*   Updated: 2024/03/29 15:31:55 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	count_words(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i] != '\0')
// 	{
// 		while (s[i] == c)
// 			i++;
// 		if (s[i])
// 			count++;
// 		while (s[i] != c && s[i])
// 			i++;
// 	}
// 	return (count);
// }

// static char	**setup(char const *s, char c)
// {
// 	char	**split;

// 	if (!s)
// 		return (NULL);
// 	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!split)
// 		return (0);
// 	return (split);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**split;
// 	size_t	start;
// 	size_t	end;
// 	size_t	i;

// 	split = setup(s, c);
// 	if (!split)
// 		return (0);
// 	start = 0;
// 	end = 0;
// 	i = 0;
// 	while (i < count_words(s, c))
// 	{
// 		while (s[start] == c)
// 			start ++;
// 		end = start;
// 		while (s[end] != c && s[end])
// 			end++;
// 		split[i] = ft_substr(s, start, (end - start));
// 		start = end;
// 		i++;
// 	}
// 	split[i] = 0;
// 	return (split);
// }

// /**
static char	**ft_recursivesplit(const char *s, int row, char separator)
{
	int		i;
	char	*str;
	char	**split;

	i = 0;
	while (s[i] && s[i] != separator)
		i++;
	str = ft_substr(s, 0, i);
	if (!str)
		return (0);
	while (s[i] && s[i] == separator)
		i++;
	if (s[i] == 0)
		split = ft_calloc((row + 2), (sizeof(char *)));
	else
		split = ft_recursivesplit(s + i, row + 1, separator);
	if (!split)
		return (0);
	split[row] = str;
	return (split);
}

char	**ft_split(const char *s, char c)
{
	if (!s || !c)
		return (0);
	while (*s && *s == c)
		s++;
	if (!*s)
		return (ft_calloc(0, sizeof(char *)));
	return (ft_recursivesplit(s, 0, c));
}
