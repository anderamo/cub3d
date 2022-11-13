/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:18:13 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:33:43 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_back(t_map	*m)
{
	if (m->map[(int)(m->posx - m->dirx * m->move)]
		[(int)(m->posy)] == '0'
		&& 1.5 < (m->posx - m->dirx * m->move)
		&& 1.5 < (m->posy))
		m->posx -= m->dirx * m->move;
	if (m->map[(int)(m->posx)]
		[(int)(m->posy - m->dirx * m->move)] == '0'
		&& 1.5 < (m->posx)
		&& 1.5 < (m->posy - m->diry * m->move))
		m->posy -= m->diry * m->move;
}

void	move_player_forward(t_map	*m)
{
	if (m->map[(int)(m->posx + m->dirx * m->move)]
		[(int)(m->posy)] == '0'
		&& 1.5 < (m->posx + m->dirx * m->move)
		&& 1.5 < (m->posy))
		m->posx += m->dirx * m->move;
	if (m->map[(int)(m->posx)]
		[(int)(m->posy + m->diry * m->move)] == '0'
		&& 1.5 < (m->posx)
		&& 1.5 < (m->posy + m->diry * m->move))
		m->posy += m->diry * m->move;
}

void	move_player_left(t_map *m)
{
	double	olddirx;
	double	oldplanex;

	olddirx = m->dirx;
	m->dirx = m->dirx * cos(m->rot) - m->diry * sin(m->rot);
	m->diry = olddirx * sin(m->rot) + m->diry * cos(m->rot);
	oldplanex = m->planex;
	m->planex = m->planex * cos(m->rot) - m->planey * sin(m->rot);
	m->planey = oldplanex * sin(m->rot) + m->planey * cos(m->rot);
}

void	move_player_rigth(t_map *m)
{
	double	olddirx;
	double	oldplanex;

	olddirx = m->dirx;
	m->dirx = m->dirx * cos(-m->rot) - m->diry * sin(-m->rot);
	m->diry = olddirx * sin(-m->rot) + m->diry * cos(-m->rot);
	oldplanex = m->planex;
	m->planex = m->planex * cos(-m->rot) - m->planey * sin(-m->rot);
	m->planey = oldplanex * sin(-m->rot) + m->planey * cos(-m->rot);
}

int	move_player(void *param)
{
	t_map	*m_val;

	m_val = param;
	create_map(m_val, 0, 0);
	if (m_val->left)
		move_player_left(m_val);
	if (m_val->bwd)
		move_player_back(m_val);
	if (m_val->right)
		move_player_rigth(m_val);
	if (m_val->fwd)
		move_player_forward(m_val);
	return (0);
}
