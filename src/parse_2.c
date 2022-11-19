/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:15:09 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/18 17:37:57 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	p_file_3(t_map *m_val, char *line_item, char **tmp_line, char **line)
{
	if (ft_strcmp(line_item, NO_STR_SEARCH) == 0)
	{
		if (get_no_str(m_val, line_item, tmp_line) == -1)
			return (-1);
	}
	else if (ft_strcmp(line_item, SO_STR_SEARCH) == 0)
	{
		if (get_so_str(m_val, line_item, tmp_line) == -1)
			return (-1);
	}
	else if (ft_strcmp(line_item, WE_STR_SEARCH) == 0)
	{
		if (get_we_str(m_val, line_item, tmp_line) == -1)
			return (-1);
	}
	else if (ft_strcmp(line_item, EA_STR_SEARCH) == 0)
	{
		if (get_ea_str(m_val, line_item, tmp_line) == -1)
			return (-1);
	}
	else if (ft_strcmp(line_item, FLOOR_STR_SEARCH) == 0)
	{
		if (get_floor_str(m_val, line_item, tmp_line) == -1)
			return (-1);
	}
	else if (ft_strcmp(line_item, ROOF_STR_SEARCH) == 0)
	{
		if (get_roof_str(m_val, line_item, tmp_line) == -1)
			return (-1);
	}
	else
	{
		p_map(m_val, tmp_line, line, line_item);
		return (0);
	}
	return (1);
}

int	p_file_2(char **line, char *tmp_line, int line_str_pos, t_map *m_val)
{
	char	*line_item;
	int 	return_value;

	while (1)
	{
		line_item = strtok_r(tmp_line, " ", &tmp_line);
		if (line_item == NULL)
			break ;
		if (line_str_pos++ == 0)
		{
			return_value = p_file_3(m_val, line_item, &tmp_line, line);
			if (return_value == -1)
				return (-1);
			else if (return_value == 0)
				break ;
		}
	}
	if (line_str_pos > 1)
		return (-1);
	return (0);
}

int	p_file(t_map *m_val, char *file_str, char *tmp_line, char *line)
{
	m_val->fd = open((const char *) file_str, O_RDONLY);
	if (!(m_val->fd))
		return (parse_return(line));
	while (1)
	{
		line = get_next_line(m_val->fd);
		if (line == NULL)
			break ;
		tmp_line = line;
		if (check_is_empty_line(line) == 0)
		{
			if (line != NULL)
				free(line);
			continue ;
		}
		tmp_line[ft_strlen(tmp_line) - 1] = '\0';
		if (p_file_2(&line, tmp_line, 0, m_val) == -1)
			return (parse_return(line));
		if (line != NULL)
			free(line);
	}
	return (0);
}
