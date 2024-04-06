/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnbrextra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:47:32 by yichan            #+#    #+#             */
/*   Updated: 2023/08/16 03:19:21 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printdbox(t_flag *fmt, long nbr)
{
	if (!fmt->minus && fmt->box)
	{
		while (!fmt->zero && (long)fmt->box-- > 0)
			write (1, " ", 1);
		if (nbr < 0 && fmt->zero)
		{
			nbr = -nbr;
			write (1, "-", 1);
		}
		while (fmt->zero && (long)fmt->box-- > 0)
			write (1, "0", 1);
	}
	else if (fmt->minus && fmt->box)
	{
		while (!fmt->zero && fmt->minus && (long)fmt->box-- > 0)
			write (1, " ", 1);
	}
}

void	precise(t_flag *fmt)
{
	while (fmt->precision--)
		write (1, "0", 1);
}

void	ft_checksign(t_flag *fmt, long nbr)
{
	if (fmt->space && nbr >= 0)
		fmt->len++;
	if (nbr < 0 && !fmt->zero)
	{
		write (1, "-", 1);
		nbr = -nbr;
	}
	else if (fmt->plus && nbr >= 0)
		write (1, "+", 1);
	else if (fmt->space)
		write (1, " ", 1);
}

void	ft_checkdash(t_flag *fmt, long nbr, unsigned long absolute)
{
	char	*ascii;

	ascii = ft_uitoa(absolute, fmt);
	if (!fmt->minus && fmt->zero)
	{
		ft_checksign(fmt, nbr);
		printdbox(fmt, nbr);
		precise(fmt);
		ft_putstr_fd(ascii, 1);
	}
	else if (!fmt->minus && !fmt ->zero)
	{
		printdbox(fmt, nbr);
		ft_checksign(fmt, nbr);
		precise(fmt);
		ft_putstr_fd(ascii, 1);
	}
	else if (fmt->minus)
	{
		ft_checksign(fmt, nbr);
		precise(fmt);
		ft_putstr_fd(ascii, 1);
		printdbox(fmt, nbr);
	}
	ft_free(ascii);
}
