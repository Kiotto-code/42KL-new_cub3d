/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:06:11 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 14:31:18 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_flag
{
	size_t		width;
	size_t		precision;
	size_t		hash;
	size_t		zero;
	size_t		minus;
	size_t		space;
	size_t		plus;
	size_t		dot;
	va_list		args;
	size_t		box;
	size_t		len;
	size_t		hole;
	size_t		precisionstate;
	size_t		precisexist;
	char		*ascii;
}	t_flag;

int				ft_printf(const char *str, ...);
void			ft_printfc(t_flag *fmt, char c);
void			ft_printfs(t_flag *fmt);
void			ft_printfp(t_flag *fmt);
void			ft_printfd(t_flag *fmt);
void			ft_printfi(t_flag *fmt);
void			ft_printfu(t_flag *fmt);
void			ft_printhexa(unsigned long long nbr, char *hex, t_flag *fmt);
void			ft_printpointer(unsigned long long nbr, char *hexa);
size_t			ft_countlen(unsigned long nbr, int base);
void			printdbox(t_flag *fmt, long nbr);
void			ft_checkdash(t_flag *fmt, long nbr, unsigned long absolute);
void			ft_checksign(t_flag *fmt, long nbr);
unsigned long	ft_absolute(long nbr);
void			precise(t_flag *fmt);
char			*ft_uitoa(unsigned long nb, t_flag *fmt);
void			ft_putascii(t_flag *fmt, char *ascii);
void			ft_printfx(t_flag *fmt, char *hexa, char *prefix);

#endif