/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_e_w_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:57:47 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/18 16:58:47 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
