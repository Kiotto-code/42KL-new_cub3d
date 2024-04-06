/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:42:50 by yichan            #+#    #+#             */
/*   Updated: 2024/03/29 15:32:36 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr;
// 	size_t	modlen;

// 	if (!s)
// 		return (NULL);
// 	if (ft_ft_strlen(s) < start)
// 		return (ft_strdup(""));
// 	modlen = ft_ft_strlen(s + start);
// 	if (modlen < len)
// 		len = modlen;
// 	substr = (char *)ft_calloc(sizeof(char) * len +1);
// 	if (!substr)
// 		return (NULL);
// 	ft_strlcpy(substr, s + start, len +1);
// 	return (substr);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*output;

// 	i = 0;
// 	j = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_ft_strlen(s))
// 		output = malloc(1);
// 	else if (len >= ft_ft_strlen(s) - start)
// 		output = malloc(sizeof(char) * (ft_ft_strlen(s) - start + 1));
// 	else
// 		output = malloc(sizeof(char) * (len + 1));
// 	if (output == NULL)
// 		return (NULL);
// 	while (i < start)
// 		i++;
// 	while (j < len && i < ft_ft_strlen(s))
// 		output[j++] = s[i++];
// 	output[j] = '\0';
// 	return (output);
// }
// if (start > ft_ft_strlen(str))
// 	return (ft_calloc(1));
// char	*ft_substr(const char *str, unsigned int start, size_t len)
// {
// 	char	*ret;

// 	if (!str)
// 		return (NULL);
// 	str = str + start;
// 	if (ft_ft_strlen(str) < len)
// 		len = ft_ft_strlen(str);
// 	ret = ft_calloc(sizeof(char) * (len + 1));
// 	if (!ret)
// 		return (NULL);
// 	ret[len] = '\0';
// 	while (len-- > 0 && len < ft_ft_strlen(str))
// 		ret[len] = str[len];
// 	return (ret);
// }

// char	*ft_substr(const char *str, unsigned int start, size_t len)
// {
// 	char	*ret;

// 	if (!str)
// 		return (NULL);
// 	if (start > ft_strlen(str))
// 		return (ft_calloc(0));
// 	else if(ft_strlen(str) < len)
// 		len = ft_strlen(str);
// 	str = str + start;
// 	ret = ft_calloc(sizeof(char) * (len + 1));
// 	if (!ret)
// 		return (NULL);
// 	ret[len] = '\0';
// 	while (len-- > 0)
// 		ret[len] = str[len];
// 	return (ret);
// }

// char	*ft_substr(const char *s, unsigned start, size_t len)
// {
// 	char	*copy;
// 	char	*ret;

// 	if (start > ft_strlen(s))
// 		return (ft_calloc(sizeof(char *)));
// 	else if (ft_strlen(s) < len)
// 		len = ft_strlen(s);
// 	s += start;
// 	copy = ft_calloc(sizeof(char) * (len +1));
// 	ret = copy;
// 	while (len-- > 0)
// 		*copy++ = *s++;
// 	return (ret);
// }

// #include <string.h>

// char	*ft_substr(const char *str, unsigned int start, size_t len)
// {
// 	char	*copy;
// 	char	*ret;

// 	if (start > ft_strlen(str))
// 		return (ft_calloc(0));
// 	else if (len > ft_strlen(str))
// 		len = ft_strlen(str);
// 	str += start;
// 	copy = ft_calloc(sizeof(char) * len);
// 	ret = copy;
// 	copy[len] = 0;
// 	while (len-- > 0)
// 		*copy++ = *str++;
// 	return (ret);
// }

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*copy;
	char	*ret;

	if (start > ft_strlen(s))
		return (ft_calloc(0, 0));
	else if (ft_strlen(s) < len)
		len = ft_strlen(s);
	s += start;
	copy = ft_calloc(sizeof(char), (len +1));
	ret = copy;
	while (len-- > 0)
		*copy++ = *s++;
	return (ret);
}
