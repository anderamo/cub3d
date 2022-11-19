/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:26:28 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:41:39 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_create_map	hit(t_create_map ray, t_map *m_val)
{
	while (ray.hit == 0)
	{
		if (ray.sidedistx < ray.sidedisty)
		{
			ray.sidedistx += ray.deltadistx;
			ray.mapx += ray.stepx;
			ray.side = 0;
			ray.wall_type = 1;
		}
		else
		{
			ray.sidedisty += ray.deltadisty;
			ray.mapy += ray.stepy;
			ray.side = 1;
			ray.wall_type = 3;
		}
		if (m_val->map[ray.mapx][ray.mapy] > '0')
			ray.hit = 1;
	}
	if (ray.side == 0)
		ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
	else
		ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
	return (ray);
}

t_create_map	how_much_draw(t_create_map ray, t_map *m_val)
{
	ray.lineheight = (int)(1000 / ray.perpwalldist);
	ray.drawstart = -ray.lineheight / 2 + 1000 / 2;
	if (ray.drawstart < 0)
		ray.drawstart = 0;
	ray.drawend = ray.lineheight / 2 + 1000 / 2;
	if (ray.drawend >= 1000)
		ray.drawend = 1000 - 1;
	if (ray.side == 0)
		ray.wallx = m_val->posy + ray.perpwalldist * ray.raydiry;
	else
		ray.wallx = m_val->posx + ray.perpwalldist * ray.raydirx;
	ray.wallx -= floor((ray.wallx));
	ray.texx = (int)(ray.wallx * (double)(64));
	if (ray.side == 0 && ray.raydirx > 0)
	{
		ray.wall_type = 0;
		ray.texx = 64 - ray.texx - 1;
	}
	if (ray.side == 1 && ray.raydiry < 0)
	{
		ray.wall_type = 2;
		ray.texx = 64 - ray.texx - 1;
	}
	return (ray);
}

int	texturize_walls(t_map *map, uint8_t i)
{
	map->pov.i_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			"./textures/snipe_pov.xpm", &map->pov.i_w, &map->pov.i_h);
	mlx_put_image_to_window(map->mlx_ptr, map->w_ptr, map->pov.i_ptr, 290, 400);
	map->wall[0].i_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->no_str, &map->wall[0].i_w, &map->wall[0].i_h);
	map->wall[1].i_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->so_str, &map->wall[1].i_w, &map->wall[1].i_h);
	map->wall[2].i_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->ea_str, &map->wall[2].i_w, &map->wall[2].i_h);
	map->wall[3].i_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->we_str, &map->wall[3].i_w, &map->wall[3].i_h);
	if (map->wall[0].i_ptr == NULL || map->wall[1].i_ptr == NULL
		|| map->wall[2].i_ptr == NULL || map->wall[3].i_ptr == NULL)
		return (-1);
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

t_create_map	determine_position(t_create_map ray, t_map *m_val)
{
	if (ray.raydirx < 0)
	{
		ray.stepx = -1;
		ray.sidedistx = (m_val->posx - ray.mapx) * ray.deltadistx;
	}
	else
	{
		ray.stepx = 1;
		ray.sidedistx = (ray.mapx + 1.0 - m_val->posx) * ray.deltadistx;
	}
	if (ray.raydiry < 0)
	{
		ray.stepy = -1;
		ray.sidedisty = (m_val->posy - ray.mapy) * ray.deltadisty;
	}
	else
	{
		ray.stepy = 1;
		ray.sidedisty = (ray.mapy + 1.0 - m_val->posy) * ray.deltadisty;
	}
	return (ray);
}

int	rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
