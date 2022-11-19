/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:12:25 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:39:44 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_create_map	init_ray_struct(t_create_map ray, t_map *m_val, int x)
{
	ray.camerax = 2 * x / (double)1000 - 1;
	ray.raydirx = m_val->dirx + m_val->planex * ray.camerax;
	ray.raydiry = m_val->diry + m_val->planey * ray.camerax;
	ray.mapx = (int)m_val->posx;
	ray.mapy = (int)m_val->posy;
	if (ray.raydirx == 0)
		ray.deltadistx = 1e30;
	else
		ray.deltadistx = fabs(1 / ray.raydirx);
	if (ray.raydiry == 0)
		ray.deltadisty = 1e30;
	else
		ray.deltadisty = fabs(1 / ray.raydiry);
	ray.hit = 0;
	ray.wall_type = 0;
	return (ray);
}

t_map	*init_new_map_struc_2(t_map *m_val)
{
	m_val->right = 0;
	m_val->move = 0.05;
	m_val->rot = 0.05;
	m_val->img.i_ptr = NULL;
	m_val->pov.i_ptr = NULL;
	m_val->pov_shot.i_ptr = NULL;
	m_val->wall[0].i_ptr = NULL;
	m_val->wall[1].i_ptr = NULL;
	m_val->wall[2].i_ptr = NULL;
	m_val->wall[3].i_ptr = NULL;
	m_val->mlx_ptr = NULL;
	m_val->w_ptr = NULL;
	m_val->map_created = 0;
	return (m_val);
}

t_map	*init_new_map_struct(void)
{
	t_map	*m_val;

	m_val = (t_map *)malloc(sizeof(t_map));
	m_val->ea_str = NULL;
	m_val->no_str = NULL;
	m_val->so_str = NULL;
	m_val->we_str = NULL;
	m_val->floor_str = NULL;
	m_val->roof_str = NULL;
	m_val->map = NULL;
	m_val->color_r = 0;
	m_val->color_g = 0;
	m_val->color_b = 0;
	m_val->r_color = -1;
	m_val->f_color = -1;
	m_val->posx = 0;
	m_val->posy = 0;
	m_val->fwd = 0;
	m_val->bwd = 0;
	m_val->left = 0;
	m_val = init_new_map_struc_2(m_val);
	return (m_val);
}
