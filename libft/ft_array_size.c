/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:09:08 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/02 07:39:51 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_array_size(char **arr)
{
    int		size;

    if (!arr || !(*arr))
        return (0);
    size = 0;
    while (arr[size])
        size++;
    return (size);
}
