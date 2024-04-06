/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:09:18 by yichan            #+#    #+#             */
/*   Updated: 2022/08/08 15:17:16 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfp(t_flag *fmt)
{
	unsigned long	pointer;
	size_t			pointerlen;

	pointer = va_arg(fmt->args, unsigned long);
	pointerlen = ft_countlen((unsigned long)pointer, 16) + 2;
	if (fmt->width > pointerlen)
		fmt->box = fmt->width - pointerlen;
	fmt->len += fmt->box + pointerlen;
	if (fmt->minus)
	{
		write(1, "0x", 2);
		ft_printpointer(pointer, "0123456789abcdef");
		while (fmt->box--)
			write(1, " ", 1);
	}
	else
	{
		while (fmt->box--)
			write(1, " ", 1);
		write(1, "0x", 2);
		ft_printpointer(pointer, "0123456789abcdef");
	}
}
