/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:56:53 by yichan            #+#    #+#             */
/*   Updated: 2023/08/16 03:19:21 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*intialize the variable for format modification*/
static void	state_setup(t_flag *fmt)
{
	fmt->width = 0;
	fmt->precision = 0;
	fmt->precisionstate = 0;
	fmt->precisexist = 0;
	fmt->hash = 0;
	fmt->zero = 0;
	fmt->minus = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->dot = 0;
	fmt->box = 0;
	fmt->hole = 0;
}

/*/modified the format when go through flags instead of conversion-type*/
static void	ft_subflag(char c, t_flag *fmt)
{
	if (ft_isdigit(c))
	{
		if (fmt->dot)
		{
			fmt->precision = fmt->precision * 10 + c - '0';
			fmt->precisexist = 1;
		}
		else
		{
			if (!fmt->width && c == '0')
				fmt->zero = 1;
			else
				fmt->width = fmt->width * 10 + c - '0';
		}
	}
	else if (c == '#')
		fmt->hash += 1;
	else if (c == '-')
		fmt->minus += 1;
	else if (c == ' ')
		fmt->space += 1;
	else if (c == '+')
		fmt->plus += 1;
	else if (c == '.')
		fmt->dot += 1;
}

/*// go through all the character one by o
// ne to check its flag and conversion type
// call subflag('ft_subflag') function
//  if detect flags symbols
// apply the relevant function when go 
//through each conversion-type(using 'ft_strchr')**/
static char	*main_reader(char *str, t_flag *fmt)
{
	while (*str && !ft_strchr("cspdiuxX%", *str))
	{
		ft_subflag(*str, fmt);
		str++;
	}
	if (*str == 'c')
		ft_printfc(fmt, va_arg(fmt->args, int));
	else if (*str == 's')
		ft_printfs(fmt);
	else if (*str == 'p')
		ft_printfp(fmt);
	else if (*str == 'd')
		ft_printfi(fmt);
	else if (*str == 'i')
		ft_printfi(fmt);
	else if (*str == 'u')
		ft_printfu(fmt);
	else if (*str == 'x')
		ft_printfx(fmt, "0123456789abcdef", "0x");
	else if (*str == 'X')
		ft_printfx(fmt, "0123456789ABCDEF", "0X");
	else if (*str == '%')
		ft_printfc(fmt, '%');
	return (str +1);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	t_flag	*fmt;

	counter = 0;
	fmt = malloc(sizeof(t_flag));
	if (!fmt)
		return (0);
	state_setup(fmt);
	fmt->len = 0;
	va_start(fmt->args, str);
	while (*str)
	{
		if (*str == '%' && (*str++))
		{
			str = main_reader((char *)str, fmt);
			state_setup(fmt);
		}
		else if (++counter)
			ft_putchar_fd(*str++, 1);
	}
	va_end(fmt->args);
	counter += fmt->len;
	ft_free(fmt);
	return (counter);
}
