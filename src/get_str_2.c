/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:05:33 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:37:33 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_so_str(t_map *m_val, char *line_item, char **tmp_line)
{
	if (m_val->so_str == NULL)
	{
		line_item = strtok_r(*tmp_line, " ", &(*tmp_line));
		if (line_item == NULL)
			return (-1);
		m_val->so_str = ft_strdup(line_item);
	}
	else
		return (-1);
	return (0);
}

int	get_floor_str(t_map *m_val, char *line_item, char **tmp_line)
{
	if (m_val->floor_str == NULL)
	{
		line_item = strtok_r(*tmp_line, " ", &(*tmp_line));
		if (line_item == NULL)
			return (-1);
		m_val->floor_str = ft_strdup(line_item);
	}
	else
		return (-1);
	return (0);
}

int	get_roof_str(t_map *m_val, char *line_item, char **tmp_line)
{
	if (m_val->roof_str == NULL)
	{
		line_item = strtok_r(*tmp_line, " ", &(*tmp_line));
		if (line_item == NULL)
			return (-1);
		m_val->roof_str = ft_strdup(line_item);
	}
	else
		return (-1);
	return (0);
}
