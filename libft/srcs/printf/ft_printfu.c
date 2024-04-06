/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:02:24 by yichan            #+#    #+#             */
/*   Updated: 2022/08/24 14:33:51 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flagadjust(t_flag *fmt, long nbr, unsigned long absolute)
{
	if ((fmt->minus && fmt->zero) || fmt->precision >= fmt->box)
		fmt->zero = 0;
	if (fmt-> space && fmt->dot)
		fmt->box--;
	if (fmt->zero && fmt->precision < fmt->width && fmt->precisexist)
		fmt->zero = 0;
	if ((fmt->plus && nbr >= 0))
		fmt->len++;
	ft_checkdash(fmt, nbr, absolute);
}

static void	lenadjust(t_flag *fmt, size_t fulllen, long nbr,
	unsigned long absolute)
{
	if (fmt->width > (size_t)fulllen)
		fmt->box = fmt->width - fulllen - fmt->precision;
	if (fmt->precision < fmt->width)
	{
		fmt->len += fmt->box + fmt->precision + fulllen;
		if (fmt->width == fmt->precisionstate
			&& fmt->precisexist && nbr < 0 && !fmt->zero)
			fmt->len++;
		else if (fmt->width < fmt->precisionstate
			&& fmt->precisexist && nbr > 0 && fmt->zero)
			fmt->len++;
		else if (fmt->zero && nbr < 0
			&& fmt->precisionstate == fmt->width && fmt->zero)
			fmt->len++;
	}
	else
		fmt->len += fmt->precision + fulllen;
	flagadjust(fmt, nbr, absolute);
}

void	ft_printfu(t_flag *fmt)
{
	unsigned long	nbrlen;
	size_t			fulllen;
	long			nbr;
	unsigned long	absolute;

	fmt->precisionstate = fmt->precision;
	fulllen = 0;
	nbr = (long)va_arg(fmt->args, unsigned);
	if (nbr == 0 && fmt->dot && !fmt->width && !fmt->precision)
		return ;
	if (nbr < 0)
		fulllen++;
	absolute = ft_absolute(nbr);
	nbrlen = ft_countlen(absolute, 10);
	fulllen += nbrlen;
	if (fmt->precision >= nbrlen)
		fmt->precision -= nbrlen;
	else if (fmt->precision < nbrlen)
		fmt->precision = 0;
	if (fmt->precisionstate == nbrlen && fmt->zero && nbr < 0)
		fmt->len--;
	lenadjust(fmt, fulllen, nbr, absolute);
}
