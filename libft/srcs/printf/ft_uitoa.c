/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:25:20 by yichan            #+#    #+#             */
/*   Updated: 2022/08/08 19:54:56 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count(unsigned long n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i ++;
	}
	return (i);
}

char	*ft_uitoa(unsigned long nb, t_flag *fmt)
{
	char		*res;
	size_t		i;

	i = count(nb);
	if (!fmt->precisionstate && fmt->dot && nb == 0)
		return (ft_strdup(" "));
	if (nb == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (i--)
	{
		res[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (res);
}
