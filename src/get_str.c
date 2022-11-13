/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:05:33 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:08:40 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_no_str(t_map *m_val, char *line_item, char **tmp_line)
{
	if (m_val->no_str == NULL)
	{
		line_item = strtok_r(*tmp_line, " ", &(*tmp_line));
		if (line_item == NULL)
			return (-1);
		m_val->no_str = ft_strdup(line_item);
	}
	else
		return (-1);
	return (0);
}

int	get_ea_str(t_map *m_val, char *line_item, char **tmp_line)
{
	if (m_val->ea_str == NULL)
	{
		line_item = strtok_r(*tmp_line, " ", &(*tmp_line));
		if (line_item == NULL)
			return (-1);
		m_val->ea_str = ft_strdup(line_item);
	}
	else
		return (-1);
	return (0);
}

int	get_we_str(t_map *m_val, char *line_item, char **tmp_line)
{
	if (m_val->we_str == NULL)
	{
		line_item = strtok_r(*tmp_line, " ", &(*tmp_line));
		if (line_item == NULL)
			return (-1);
		m_val->we_str = ft_strdup(line_item);
	}
	else
		return (-1);
	return (0);
}
