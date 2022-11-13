/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:09:08 by aamorin-          #+#    #+#             */
/*   Updated: 2021/06/02 07:39:51 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_freetab(char **tab)
{
    int	i;

    i = 0;
    if (!tab)
        return (0);
    while (tab[i] != NULL)
    {
        if (tab[i])
            free(tab[i]);
        i++;
    }
    free(tab);
    return (1);
}
