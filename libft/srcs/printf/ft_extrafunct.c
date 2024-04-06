/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extrafunct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:37:23 by yichan            #+#    #+#             */
/*   Updated: 2024/01/09 17:52:11 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printpointer(unsigned long long nbr, char *hexa)
{
	if (nbr / 16)
		ft_printpointer(nbr / 16, hexa);
	ft_putchar_fd(hexa[nbr % 16], 1);
}

void	ft_printhexa(unsigned long long nbr, char *hexa, t_flag *fmt)
{
	if (nbr == 0 && (!fmt->precisexist || !fmt->precisionstate) && fmt->dot)
	{
		if (!fmt->minus)
			fmt->len --;
		return ;
	}
	if (nbr / 16)
		ft_printhexa(nbr / 16, hexa, fmt);
	ft_putchar_fd(hexa[nbr % 16], 1);
}

size_t	ft_countlen(unsigned long nbr, int base)
{
	if (!(nbr / base) || nbr == 0)
		return (1);
	return (1 + ft_countlen(nbr / base, base));
}

unsigned long	ft_absolute(long nbr)
{
	unsigned long	absolute;

	if (nbr < 0)
		return (nbr * -1);
	else
		absolute = nbr;
	return (absolute);
}

// size_t	ft_max(int a, int b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }
