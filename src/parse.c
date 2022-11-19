/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:15:09 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/18 17:37:57 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_return(char *line)
{
	if (line != NULL)
		free(line);
	return (-1);
}

char	*p_map_2(char **line, t_map *m_val, char *buffer_map)
{
	m_val->height = 1;
	while (1)
	{
		*line = get_next_line(m_val->fd);
		if (*line == NULL)
			break ;
		if (check_is_empty_line(*line) == 0)
			break ;
		buffer_map = ft_strjoin(buffer_map, *line);
		if (m_val->width < (int)ft_strlen(*line))
			m_val->width = (int)ft_strlen(*line);
		m_val->height++;
		if (*line != NULL)
			free(*line);
		*line = NULL;
	}
	return (buffer_map);
}

void	p_map_add(char *line_item, t_map *m_val, int index, char **tmp_line)
{
	while (1)
	{
		line_item = strtok_r(*tmp_line, "\n", &(*tmp_line));
		if (line_item == NULL)
			break ;
		m_val->map[index] = (char *)malloc(sizeof(char) * m_val->width + 1);
		ft_memset(m_val->map[index], ' ', m_val->width);
		ft_memcpy(m_val->map[index], line_item, ft_strlen(line_item));
		m_val->map[index][m_val->width] = '\0';
		index++;
	}
}

void	p_map(t_map	*m_val, char **tmp_line, char **line, char *line_item)
{
	char	*buffer_map;

	if (*tmp_line != NULL)
		*line = ft_strjoin_space(*line, *tmp_line);
	m_val->width = (int)ft_strlen(*line);
	line[0][m_val->width - 1] = '\n';
	buffer_map = ft_strdup_free(*line);
	buffer_map = p_map_2(line, m_val, buffer_map);
	m_val->map = (char **) malloc(sizeof(char *) * (m_val->height + 1));
	*tmp_line = buffer_map;
	p_map_add(line_item, m_val, 0, tmp_line);
	free(buffer_map);
	m_val->map[m_val->height] = NULL;
	*line = NULL;
}
