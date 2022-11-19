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
