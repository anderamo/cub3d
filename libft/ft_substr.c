/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:28:14 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/18 17:02:42 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	s_size;
	size_t	i;

	if (!s)
		return (NULL);
	s_size = ft_strlen((char *)s);
	if (start > s_size)
		return (ft_strdup(""));
	if (s_size < len)
		len = s_size;
	array = malloc((len * sizeof(char)) + 1);
	if (!(array))
		return (NULL);
	i = 0;
	while (i < len && i + start < s_size)
	{
		array[i] = s[i + start];
		i++;
	}
	array[i] = '\0';
	return (array);
}
