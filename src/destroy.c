/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:28:53 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:37:28 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	destroy_map_struct_2(t_map *m_val)
{
	m_val->img.i_ptr = NULL;
	if (m_val->pov_shot.i_ptr != NULL)
		mlx_destroy_image(m_val->mlx_ptr, m_val->pov_shot.i_ptr);
	m_val->pov_shot.i_ptr = NULL;
	if (m_val->pov.i_ptr != NULL)
		mlx_destroy_image(m_val->mlx_ptr, m_val->pov.i_ptr);
	m_val->pov.i_ptr = NULL;
	if (m_val->wall[0].i_ptr != NULL)
		mlx_destroy_image(m_val->mlx_ptr, m_val->wall[0].i_ptr);
	m_val->wall[0].i_ptr = NULL;
	if (m_val->wall[1].i_ptr != NULL)
		mlx_destroy_image(m_val->mlx_ptr, m_val->wall[1].i_ptr);
	m_val->wall[1].i_ptr = NULL;
	if (m_val->wall[2].i_ptr != NULL)
		mlx_destroy_image(m_val->mlx_ptr, m_val->wall[2].i_ptr);
	m_val->wall[2].i_ptr = NULL;
	if (m_val->wall[3].i_ptr != NULL)
		mlx_destroy_image(m_val->mlx_ptr, m_val->wall[3].i_ptr);
	m_val->wall[3].i_ptr = NULL;
	if (m_val->mlx_ptr != NULL && m_val->w_ptr != NULL)
		mlx_destroy_window(m_val->mlx_ptr, m_val->w_ptr);
	if (m_val->mlx_ptr != NULL)
		free(m_val->mlx_ptr);
	free(m_val);
	return (-1);
}

int	destroy_map_struct(t_map *m_val, bool print)
{
	if (print == 1)
		printf("Error.\n");
	if (m_val->ea_str != NULL)
		free(m_val->ea_str);
	m_val->ea_str = NULL;
	if (m_val->no_str != NULL)
		free(m_val->no_str);
	m_val->no_str = NULL;
	if (m_val->so_str != NULL)
		free(m_val->so_str);
	m_val->so_str = NULL;
	if (m_val->we_str != NULL)
		free(m_val->we_str);
	m_val->we_str = NULL;
	if (m_val->floor_str != NULL)
		free(m_val->floor_str);
	m_val->floor_str = NULL;
	if (m_val->roof_str != NULL)
		free(m_val->roof_str);
	m_val->roof_str = NULL;
	if (m_val->map != NULL)
		ft_freetab(m_val->map);
	if (m_val->img.i_ptr != NULL)
		mlx_destroy_image(m_val->mlx_ptr, m_val->img.i_ptr);
	return (destroy_map_struct_2(m_val));
}
