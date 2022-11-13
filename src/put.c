/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:33:16 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:45:01 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->b_pixel / 8));
	*(unsigned int *) dst = color;
}

t_create_map	put_texturize_pos_color(t_create_map ray, t_map *m_val, int x)
{
	int	i;
	int	y;

	ray.step = 1.0 * 64 / ray.lineheight;
	ray.texpos = (ray.drawstart - 1000 / 2 + ray.lineheight / 2) * ray.step;
	y = ray.drawstart;
	while (y < ray.drawend)
	{
		ray.texy = (int)ray.texpos & (64 - 1);
		ray.texpos += ray.step;
		i = 0;
		while (i < 4)
		{
			ray.color[i] = m_val->wall[ray.wall_type].addr[256 * ray.texy
				+ (ray.texx * 4) + i];
			if (ray.side == 1)
				ray.color[i] = (ray.color[i] >> 1) & 8355711;
			i++;
		}
		my_mlx_pixel_put(&m_val->img, x, y, rgb(ray.color[2],
				ray.color[1], ray.color[0]));
		y++;
	}
	return (ray);
}
