/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:58:30 by yichan            #+#    #+#             */
/*   Updated: 2024/04/03 10:23:29 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// double	*str2arr(char	*num_arr_in_str)
// {
// 	char	**array;
// 	double	*ret;
// 	int		i;

// 	array = ft_split(num_arr_in_str, ',');
// 	i = -1;
// 	while (array[++i])
// 		printf("check arr: %s\n", array[i]);
// 	ret = ft_malloc(sizeof(double) * i);
// 	i = 0;
// 	while (array[i])
// 	{
// 		ret[i] = ft_atod(array[i]);
// 		i++;
// 	}
// 	array_liberator(array);
// 	return (ret);
// }

// int	main(void)
// {
// 	const char		*str = ft_strdup("123,345,456");
// 	const double	*ret = str2arr(str);

// 	for (int i = 0; i<3; i++)
// 		printf("here; %f\n", ret[i]);
// }
