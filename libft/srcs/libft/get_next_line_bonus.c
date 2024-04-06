/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:23:47 by yichan            #+#    #+#             */
/*   Updated: 2023/08/16 03:19:21 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_readline(int fd, char *str)
{
	char	*buff;
	int		r_ret;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	r_ret = 1;
	while (!ft_strchr2(str, '\n') && r_ret != 0)
	{
		r_ret = read(fd, buff, BUFFER_SIZE);
		if (r_ret == -1)
		{
			ft_free(buff);
			return (NULL);
		}
		buff[r_ret] = '\0';
		str = joinfree(str, buff);
	}
	ft_free(buff);
	return (str);
}

char	*currentline(char *str)
{
	int		c_len;
	char	*pointer;
	char	*ret;

	c_len = 0;
	if (!str[c_len])
		return (NULL);
	while ((str)[c_len] && (str)[c_len] != '\n')
		c_len++;
	ret = malloc (sizeof(char) * (c_len + 2));
	if (!ret)
		return (NULL);
	pointer = ret;
	while (*str != '\n' && *str)
		*ret++ = *str++;
	if (*str == '\n')
		*ret++ = (*str);
	*ret = '\0';
	return (pointer);
}

char	*remain(char *str)
{
	char	*ret;
	int		c_len;
	int		i;

	c_len = 0;
	while ((str)[c_len] && (str)[c_len] != '\n')
		c_len++;
	if (!str[c_len])
	{
		ft_free(str);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen2(str) - c_len + 1));
	c_len++;
	i = 0;
	while (str[c_len])
		ret[i++] = str[c_len++];
	ret[i] = '\0';
	ft_free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*ret;

	if (BUFFER_SIZE <= 0 || fd > 1024 || fd < 0)
		return (NULL);
	str[fd] = gnl_readline(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	ret = currentline (str[fd]);
	str[fd] = remain (str[fd]);
	return (ret);
}
