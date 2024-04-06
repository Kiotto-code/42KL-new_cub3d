/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:54:22 by yichan            #+#    #+#             */
/*   Updated: 2024/03/30 22:12:44 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_arr(char **arr, char *prompt)
{
	size_t	i;

	if (!arr)
	{
		ft_printf(BLUE"ft_print_arr FAILED: %s\n", prompt);
		return ;
	}
	i = 0;
	ft_printf(BLUE"ft_print_arr: %s\n", prompt);
	while (arr[i])
	{
		if (prompt)
			ft_putstr_fd(prompt, 1);
		ft_printf(BLUE"CHECKING[%i]: |%s| \n"RESET, i, arr[i]);
		fflush(stdout);
		i++;
	}
}
