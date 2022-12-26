/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:01:03 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/18 17:14:19 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int a, char **v)
{
	t_map			*m_val;
	t_check_map		check;

	m_val = init_new_map_struct();
	check.y = -1;
	if (a != 2 || c_file(v[1]) == -1 || (p_file(m_val, v[1], 0, 0) == -1)
		|| (check_map((void *)m_val, m_val->height, m_val->width, check) == -1)
		|| create_f_colors(m_val, 0) == -1 || create_r_colors(m_val, 0) == -1
		|| m_val->posx == 0 || m_val->posy == 0)
		return (destroy_map_struct(m_val, 1));
	m_val->mlx_ptr = mlx_init();
	m_val->w_ptr = mlx_new_window(m_val->mlx_ptr, 1000, 1000, "Raycaster");
	if (texturize_walls(m_val, 0) == -1)
		return (destroy_map_struct(m_val, 1));
	mlx_hook(m_val->w_ptr, 2, 1L << 0, key_press_manager, m_val);
	mlx_hook(m_val->w_ptr, 3, 1L << 1, key_release_manager, m_val);
	mlx_hook(m_val->w_ptr, 17, 1L << 17, close_win_x, m_val);
	mlx_loop_hook(m_val->mlx_ptr, move_player, m_val);
	mlx_loop(m_val->mlx_ptr);
	destroy_map_struct(m_val, 0);
	return (0);
}
