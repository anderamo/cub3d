/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:24:49 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:36:21 by aamorin-         ###   ########.fr       */
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

int	check_is_empty_line(char *file_str)
{
	size_t	file_str_len;
	size_t	i;

	i = 0;
	file_str_len = ft_strlen(file_str);
	while (i < file_str_len)
	{
		if (file_str[i] != ' ')
			break ;
		i++;
	}
	if (i == file_str_len - 1)
	{
		if (file_str[i] == '\n')
			return (0);
	}
	else
		return (-1);
	return (0);
}

int check_map(void *map, int heigth, int width)
{
	int     y;
	int     x;
	char    c;
	char    last_char;
	t_map   *m_val = map;

	if (m_val->map == NULL || *m_val->map == NULL)
		return (-1);
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (m_val->map[y][x] != '\0') {
			if (m_val->map[y][x] == 'N' ||
				m_val->map[y][x] == 'W' ||
				m_val->map[y][x] == 'E' ||
				m_val->map[y][x] == 'S') {
				if (m_val->map[y][x] == 'N') {
					m_val->dirx = -1, m_val->diry = 0;
					m_val->planex = 0, m_val->planey = 0.66;
				}
				if (m_val->map[y][x] == 'E') {
					m_val->dirx = 0, m_val->diry = 1;
					m_val->planex = 0.66, m_val->planey = 0;
				}
				if (m_val->map[y][x] == 'W') {
					m_val->dirx = 0, m_val->diry = -1;
					m_val->planex = -0.66, m_val->planey = 0;
				}
				if (m_val->map[y][x] == 'S') {
					m_val->dirx = 1, m_val->diry = 0;
					m_val->planex = 0, m_val->planey = -0.66;
				}
				if (m_val->posx != 0 || m_val->posy != 0)
					return (-1);
				m_val->map[y][x] = '0';
				m_val->posx = y + 0.5;
				m_val->posy = x + 0.5;
			} else if (m_val->map[y][x] == 32 ||
						m_val->map[y][x] == '\0' ||
						m_val->map[y][x] == '5' ||
						m_val->map[y][x] == '1' ||
						m_val->map[y][x] == '0') {
				if (y == 0 || y == heigth - 1) {
					c = m_val->map[y][x];
					if (c != '1' && c != 32 && c != '\0') {
						return (-1);
					}
					if (c == 32) {
						c = m_val->map[y == heigth - 1 ? y : y + 1][x];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
						c = m_val->map[y == 0 ? y : y - 1][x];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
						c = m_val->map[y][x + 1 < width ? x + 1 : x];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
						c = m_val->map[y][x == 0 ? x : x - 1];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
					} else
						last_char = c;
				} else {
					c = m_val->map[y][x];
					if (c == 32) {
						c = m_val->map[y + 1][x];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
						c = m_val->map[y - 1][x];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
						c = m_val->map[y][x + 1 < width ? x + 1 : x];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
						c = m_val->map[y][x == 0 ? x : x - 1];
						if (c != '1' && c != 32 && c != '\0') {
							return (-1);
						}
					} else
						last_char = c;
				}
			} else
				return (-1);
			x++;
		}
		if (last_char != '1')
			return (-1);
		y++;
	}
	if (m_val->posx == 0 || m_val->posy == 0)
		return (-1);
	return (0);
}
