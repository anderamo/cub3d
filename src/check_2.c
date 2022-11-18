/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:24:49 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/18 16:59:28 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	c_file(char *file_str)
{
	size_t	file_str_len;

	file_str_len = ft_strlen(file_str);
	if (file_str_len < 4)
	{
		printf("Wrong file name)\n");
		return (-1);
	}
	if (ft_strcmp(file_str + (file_str_len - 4), FILE_EXTENSION) != 0)
	{
		printf("Wrong file extension (.cub)\n");
		return (-1);
	}
	return (0);
}
