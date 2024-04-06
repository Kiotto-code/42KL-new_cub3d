/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:34 by yichan            #+#    #+#             */
/*   Updated: 2023/01/28 19:11:52 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief an error function to exit program w custom message displayed
 * 
 * @param str print message
 * @param stat exit status 0: SUCCESS && 1: FAILURE
 */
void	ft_error(char *str, int stat)
{
	if (stat != 0 && stat != 1)
		ft_error("Wrong STAT input", 1);
	ft_putendl_fd(str, stat + 1);
	exit(stat);
}
