/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:09:08 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/02 07:39:51 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_freetab_int(int **tab, int size)
{
    int	i;

    if (!tab || !(*tab))
        return (0);

    i = 0;
    while (size > i)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    return (1);
}
