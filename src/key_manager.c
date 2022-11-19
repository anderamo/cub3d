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

void	key_add_pov(t_map *m_val)
{
	mlx_clear_window(m_val->mlx_ptr, m_val->w_ptr);
	mlx_put_image_to_window(m_val->mlx_ptr, m_val->w_ptr,
		m_val->img.i_ptr, 0, 0);
	mlx_put_image_to_window(m_val->mlx_ptr, m_val->w_ptr,
		m_val->pov_shot.i_ptr, 290, 410);
}

int	key_press_manager(int keycode, void *param)
{
	t_map	*m_val;

	m_val = (t_map *)param;
	if (keycode == '5')
	{
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
		key_add_pov(m_val);
	return (1);
}
