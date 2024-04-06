/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:57:23 by yichan            #+#    #+#             */
/*   Updated: 2023/06/02 23:34:03 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

int		gnl_strlen(char *s);
char	*gnl_strchr(char *s, char c);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, int start, int len);
void	*gnl_calloc(int count, int size);

size_t	ft_strlen2(char *str);
char	*ft_strchr2(char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
char	*joinfree(char *str1, char *str2);

#endif