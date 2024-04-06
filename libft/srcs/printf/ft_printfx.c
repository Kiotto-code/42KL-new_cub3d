/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:14:54 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 14:34:03 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_max(size_t a, size_t b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }

static void	ft_adjustflag(t_flag *fmt, char *hexa,
	unsigned long pointer, char *prefix)
{
	if (fmt->minus && pointer == 0 && !fmt->precisionstate
		&& fmt->dot && !fmt->width)
		fmt->len --;
	if (fmt->width && fmt->dot && !fmt->precisionstate && pointer == 0)
		fmt->box ++;
	if (fmt->width && fmt->dot && !fmt->precisionstate
		&& pointer == 0 && !fmt->minus)
		fmt->len ++;
	if (fmt->minus)
	{
		if (fmt->hash && pointer != 0)
			write(1, prefix, 2);
		precise(fmt);
		ft_printhexa(pointer, hexa, fmt);
		printdbox (fmt, 1);
	}
	else
	{
		printdbox (fmt, 1);
		if (fmt->hash && pointer != 0)
			write(1, prefix, 2);
		precise(fmt);
		ft_printhexa(pointer, hexa, fmt);
	}
}

void	ft_printfx(t_flag *fmt, char *hexa, char *prefix)
{
	unsigned long	pointer;
	size_t			pointerlen;

	fmt->precisionstate = fmt->precision;
	pointer = va_arg(fmt->args, unsigned int);
	pointerlen = ft_countlen((unsigned long)pointer, 16)
		+ (fmt->hash && pointer != 0) * 2;
	if (fmt->width >= fmt->precision && fmt->dot)
		fmt->zero = 0;
	if ((int)fmt->width >= ft_max(pointerlen, fmt->precision))
		fmt->box = fmt->width - ft_max(pointerlen, fmt->precision);
	fmt->precision = (fmt->precision >= pointerlen)
		* (fmt->precision - pointerlen);
	fmt->len += fmt->box + pointerlen + fmt->precision;
	ft_adjustflag(fmt, hexa, pointer, prefix);
}
