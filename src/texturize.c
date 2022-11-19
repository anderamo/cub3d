/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:28:53 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:37:28 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	texturize_xpm(t_map *m_val)
{
	m_val->pov_shot.i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
			"./textures/snipe_pov_shot.xpm",
			&m_val->pov_shot.i_w, &m_val->pov_shot.i_h);
	m_val->pov.i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
			"./textures/snipe_pov.xpm",
			&m_val->pov.i_w, &m_val->pov.i_h);
	m_val->wall[0].i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
			m_val->no_str, &m_val->wall[0].i_w, &m_val->wall[0].i_h);
	m_val->wall[1].i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
			m_val->so_str, &m_val->wall[1].i_w, &m_val->wall[1].i_h);
	m_val->wall[2].i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
			m_val->ea_str, &m_val->wall[2].i_w, &m_val->wall[2].i_h);
	m_val->wall[3].i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
			m_val->we_str, &m_val->wall[3].i_w, &m_val->wall[3].i_h);
}

int	texturize_walls(t_map *map, uint8_t i)
{
	texturize_xpm(map);
	if (map->wall[0].i_ptr == NULL || map->wall[1].i_ptr == NULL
		|| map->wall[2].i_ptr == NULL || map->wall[3].i_ptr == NULL
		|| map->pov.i_ptr == NULL || map->pov_shot.i_ptr == NULL)
		return (-1);
	mlx_put_image_to_window(map->mlx_ptr, map->w_ptr, map->pov.i_ptr, 290, 400);
	while (i < 4)
	{
		map->wall[i].addr = mlx_get_data_addr(map->wall[i].i_ptr,
				&map->wall[i].b_pixel, &map->wall[i].l_len,
				&map->wall[i].endian);
		i++;
	}
	mlx_do_key_autorepeatoff(map->mlx_ptr);
	return (0);
}
