/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:10:52 by yichan            #+#    #+#             */
/*   Updated: 2022/08/08 19:54:26 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfs(t_flag *fmt)
{
	char	*str;

	str = va_arg(fmt->args, char *);
	if (!str)
		str = "(null)";
	if (!fmt->dot || fmt->precision > ft_strlen(str))
		fmt->precision = ft_strlen(str);
	if (fmt->width > fmt->precision)
		fmt->box = fmt->width - fmt->precision;
	fmt->len += fmt->box + fmt->precision;
	if (fmt->minus)
	{
		write(1, str, fmt->precision);
		while (fmt->box--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (fmt->box--)
			ft_putchar_fd(' ', 1);
		write(1, str, fmt->precision);
	}
}
