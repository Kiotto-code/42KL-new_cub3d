/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:42:47 by yichan            #+#    #+#             */
/*   Updated: 2024/03/29 15:46:30 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define BLACK	"\e[30m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"
# define WHITE	"\e[37m"
# define RESET	"\033[0m"

# define BRIGHT_BLACK	"\e[90m"
# define BRIGHT_RED		"\e[91m"
# define BRIGHT_GREEN	"\e[92m"
# define BRIGHT_YELLOW	"\e[93m"
# define BRIGHT_BLUE	"\e[94m"
# define BRIGHT_PURPLE	"\e[95m"
# define BRIGHT_CYAN	"\e[96m"
# define BRIGHT_WHITE	"\e[97m"

# define BG_BLACK	"\e[40m"
# define BG_RED		"\e[41m"
# define BG_GREEN	"\e[42m"
# define BG_YELLOW	"\e[43m"
# define BG_BLUE	"\e[44m"
# define BG_PURPLE	"\e[45m"
# define BG_CYAN	"\e[46m"
# define BG_WHITE	"\e[47m"

# define BG_BRIGHT_BLACK	"\e[100m"
# define BG_BRIGHT_RED		"\e[101m"
# define BG_BRIGHT_GREEN	"\e[102m"
# define BG_BRIGHT_YELLOW	"\e[103m"
# define BG_BRIGHT_BLUE		"\e[104m"
# define BG_BRIGHT_PURPLE	"\e[105m"
# define BG_BRIGHT_CYAN		"\e[106m"
# define BG_BRIGHT_WHITE	"\e[107m"

typedef struct s_stk
{
	int				nbr;
	int				index;
}			t_stk;

/**
 * @brief 
 * content -> envp
 * 
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_stk	*ft_lstnew2(int content);
int		ft_isalpha(int n);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_max(int a, int b);
void	ft_error(char *str, int stat);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_strend(char *str, int n);
char	*ft_strjoinf(char *s1, char const*s2);
char	*ft_strjoin_con(char const *s1, char *connector, char const *s2);
int		ft_arrlen(char **arr);
char	**ft_duparr(char **env);
int		ft_arr2lst(t_list **lst, char **arr, \
			void (*add_back)(t_list **lst, t_list *new));
int		ft_replace(char **s, const char *old, const char *new, int start);
char	*ft_remove(char *input, char c);
size_t	ft_strcpy(char *dst, const char *src);
void	ft_strswitch(char **old, char *new);
int		ft_strlead(const char *s1, const char *s2);
int		ft_free(void *memory);
int		ft_is_all_space(char *str);
char	**ft_subarr(char **arr, size_t start, size_t end);
void	ft_print_arr(char **arr, char *prompt);
int		ft_replace_all(char **s, const char *old, const char *new, int start);
void	free_2d(char **arr);
bool	ft_isspace(int c);
size_t	getncount(char *str, uint8_t n);
size_t	ft_strclen(char *str, char c);
size_t	ft_strccpy(char *dst, char *src, char c);
int		ft_abs(int x);

#endif