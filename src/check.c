/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:24:49 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 19:42:57 by aamorin-         ###   ########.fr       */
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

void	n_e_w_s_2(t_map *m, int y, int x)
{
	if (m->map[y][x] == 'W')
	{
		m->dirx = 0;
		m->diry = -1;
		m->planex = -0.66;
		m->planey = 0;
	}
	if (m->map[y][x] == 'S')
	{
		m->dirx = 1;
		m->diry = 0;
		m->planex = 0;
		m->planey = -0.66;
	}
}

int	n_e_w_s(t_map *m, t_check_map check)
{
	if (m->map[check.y][check.x] == 'N')
	{
		m->dirx = -1;
		m->diry = 0;
		m->planex = 0;
		m->planey = 0.66;
	}
	if (m->map[check.y][check.x] == 'E')
	{
		m->dirx = 0;
		m->diry = 1;
		m->planex = 0.66;
		m->planey = 0;
	}
	n_e_w_s_2(m, check.y, check.x);
	if (m->posx != 0 || m->posy != 0)
		return (-1);
	m->map[check.y][check.x] = '0';
	m->posx = check.y + 0.5;
	m->posy = check.x + 0.5;
	return (1);
}

int	check_map_walls_2(t_map *m, int w, t_check_map *c)
{
	c->c = m->map[c->y][c->x];
	if (c->c == 32)
	{
		c->c = m->map[c->y + 1][c->x];
		if (c->c != '1' && c->c != 32 && c->c != '\0')
			return (-1);
		c->c = m->map[c->y - 1][c->x];
		if (c->c != '1' && c->c != 32 && c->c != '\0')
			return (-1);
		c->c = m->map[c->y][c->x + 1 < w ? c->x + 1 : c->x];
		if (c->c != '1' && c->c != 32 && c->c != '\0')
			return (-1);
		c->c = m->map[c->y][c->x == 0 ? c->x : c->x - 1];
		if (c->c != '1' && c->c != 32 && c->c != '\0')
			return (-1);
	}
	else
		c->last_char = c->c;
	return (1);
}

int	check_map_walls_position(t_map *m, int h, int w, t_check_map *c)
{
	if (c->y == h - 1)
		c->c = m->map[c->y][c->x];
	else
		c->c = m->map[c->y + 1][c->x];
	if (c->c != '1' && c->c != 32 && c->c != '\0')
		return (-1);
	if (c->y == 0)
		c->c = m->map[c->y][c->x];
	else
		c->c = m->map[c->y - 1][c->x];
	if (c->c != '1' && c->c != 32 && c->c != '\0')
		return (-1);
	if (c->x + 1 < w)
		c->c = m->map[c->y][c->x + 1];
	else
		c->c = m->map[c->y][c->x];
	if (c->c != '1' && c->c != 32 && c->c != '\0')
		return (-1);
	if (c->x == 0)
		c->c = m->map[c->y][c->x];
	else
		c->c = m->map[c->y][c->x - 1];
	if (c->c != '1' && c->c != 32 && c->c != '\0')
		return (-1);
	return (0);
}

int	check_map_walls(t_map *m, int h, int w, t_check_map *c)
{
	if (c->y == 0 || c->y == h - 1)
	{
		c->c = m->map[c->y][c->x];
		if (c->c != '1' && c->c != 32 && c->c != '\0')
			return (-1);
		if (c->c == 32)
		{
			if (check_map_walls_position(m, h, w, c) == -1)
				return (-1);
		}
		else
			c->last_char = c->c;
		return (0);
	}
	else
		return (check_map_walls_2(m, w, c));
}

int	check_map(t_map *m, int heigth, int width, t_check_map	c)
{
	while (++c.y < heigth)
	{
		c.x = -1;
		while (m->map[c.y][++c.x] != '\0')
		{
			if (m->map[c.y][c.x] == 'N' || m->map[c.y][c.x] == 'W' ||
				m->map[c.y][c.x] == 'E' || m->map[c.y][c.x] == 'S')
			{
				if (n_e_w_s(m, c) == -1)
					return (-1);
			}
			else if (m->map[c.y][c.x] == 32 || m->map[c.y][c.x] == '\0'
					|| m->map[c.y][c.x] == '1' || m->map[c.y][c.x] == '0')
			{
				if (check_map_walls(m, heigth, width, &c) == -1)
					return (-1);
			}
			else
				return (-1);
		}
		if (c.last_char != '1')
			return (-1);
	}
	if (m->posx == 0 || m->posy == 0)
		return (-1);
	return (0);
}
