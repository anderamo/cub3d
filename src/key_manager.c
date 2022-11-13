/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:20:34 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:39:48 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_win_x(t_map *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->w_ptr);
	destroy_map_struct(vars);
	exit(1);
	return (-1);
}

int	key_release_manager(int keycode, void *param)
{
	t_map	*m_val;

	m_val = (t_map *)param;
	if (keycode == 13)
		m_val->fwd = 0;
	else if (keycode == 1)
		m_val->bwd = 0;
	else if (keycode == 0)
		m_val->left = 0;
	else if (keycode == 2)
		m_val->right = 0;
	return (1);
}

int	key_press_manager(int keycode, void *param)
{
	t_map	*m_val;

    m_val = param;
	double	camerax = 2 * 500 / (double)1000 - 1;
	double	raydirx = m_val->dirx + m_val->planex * camerax;
	double	raydiry = m_val->diry + m_val->planey * camerax;
	int		mapx = (int)m_val->posx;
	int		mapy = (int)m_val->posy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx = (raydirx == 0) ? 1e30 : abs((int)(1 / raydirx));
	double	deltadisty = (raydiry == 0) ? 1e30 : abs((int)(1 / raydiry));
	int		stepx;
	int		stepy;
	int	 	hit = 0;

	m_val = (t_map *)param;
	if (keycode == '5')
	{
		mlx_destroy_window(m_val->mlx_ptr, m_val->w_ptr);
		destroy_map_struct(m_val);
		exit(1);
	}
	if (keycode == 13)
		m_val->fwd = 1;
	else if (keycode == 1)
		m_val->bwd = 1;
	else if (keycode == 0)
		m_val->left = 1;
	else if (keycode == 2)
		m_val->right = 1;
	else if (keycode == 36)
	{
		mlx_clear_window(m_val->mlx_ptr, m_val->w_ptr);
		mlx_put_image_to_window(m_val->mlx_ptr, m_val->w_ptr,
			m_val->img.i_ptr, 0, 0);
		m_val->pov_shot.i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
				"./textures/snipe_pov_shot.xpm",
				&m_val->pov_shot.i_w, &m_val->pov_shot.i_h);
		mlx_put_image_to_window(m_val->mlx_ptr, m_val->w_ptr,
			m_val->pov_shot.i_ptr, 290, 410);
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (m_val->posx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - m_val->posx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (m_val->posy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - m_val->posy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
			}
			if (m_val->map[mapx][mapy] > '0')
				hit = 1;
		}
		if (m_val->map[mapx][mapy] == '5')
			m_val->map[mapx][mapy] = '0';
	}
	return (1);
}
