/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:22:38 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/13 17:36:59 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_create_map	create_map_2(int i, t_map *m_val, t_create_map ray, int x)
{
	i = 0;
	if (m_val->f_color > -1)
		while (i++ < 500)
			my_mlx_pixel_put(&m_val->img, x, i, (int)m_val->f_color);
	i = 500;
	if (m_val->r_color > -1)
		while (i++ < 1000 - 1)
			my_mlx_pixel_put(&m_val->img, x, i, (int)m_val->r_color);
	ray = init_ray_struct(ray, m_val, x);
	ray = determine_position(ray, m_val);
	ray = hit(ray, m_val);
	ray = how_much_draw(ray, m_val);
	ray = put_texturize_pos_color(ray, m_val, x);
	return (ray);
}

int	create_map(t_map *m_val, int i, int x)
{
	t_create_map	ray;

	if (m_val->img.i_ptr != NULL)
	{
		mlx_destroy_image(m_val->mlx_ptr, m_val->img.i_ptr);
		m_val->img.i_ptr = NULL;
	}
	m_val->img.i_ptr = mlx_new_image(m_val->mlx_ptr, 1000, 1000);
	m_val->img.addr = mlx_get_data_addr(m_val->img.i_ptr, &m_val->img.b_pixel,
			&m_val->img.l_len, &m_val->img.endian);
	mlx_clear_window(m_val->mlx_ptr, m_val->w_ptr);
	while (x < 1000)
	{
		ray = create_map_2(i, m_val, ray, x);
		x++;
	}
	mlx_put_image_to_window(m_val->mlx_ptr, m_val->w_ptr,
		m_val->img.i_ptr, 0, 0);
	m_val->pov.i_ptr = mlx_xpm_file_to_image(m_val->mlx_ptr,
			"./textures/snipe_pov.xpm", &m_val->pov.i_w, &m_val->pov.i_h);
	mlx_put_image_to_window(m_val->mlx_ptr, m_val->w_ptr,
		m_val->pov.i_ptr, 290, 400);
	mlx_destroy_image(m_val->mlx_ptr, m_val->pov.i_ptr);
	return (0);
}

int	create_f_colors(t_map *m_val, uint8_t i)
{
	char	*tmp;
	char	*line_item;

	if (m_val->floor_str != NULL)
	{
		tmp = m_val->floor_str;
		line_item = strtok_r(tmp, ",", &tmp);
		while (line_item != NULL)
		{
			if (i == 0)
				m_val->color_r = ft_atoi(line_item);
			if (i == 1)
				m_val->color_g = ft_atoi(line_item);
			if (i == 2)
			m_val->color_b = ft_atoi(line_item);
			i++;
			line_item = strtok_r(tmp, ",", &tmp);
		}
		if (i != 3 || m_val->color_r < 0 || m_val->color_r > 255
			|| m_val->color_g < 0 || m_val->color_g > 255
			|| m_val->color_b < 0 || m_val->color_b > 255)
			return (-1);
		m_val->f_color = rgb(m_val->color_r, m_val->color_g, m_val->color_b);
	}
	return (1);
}

int	create_r_colors(t_map *m_val, uint8_t i)
{
	char	*tmp;
	char	*line_item;

	if (m_val->roof_str != NULL)
	{
		tmp = m_val->roof_str;
		line_item = strtok_r(tmp, ",", &tmp);
		while (line_item != NULL)
		{
			if (i == 0)
				m_val->color_r = ft_atoi(line_item);
			if (i == 1)
				m_val->color_g = ft_atoi(line_item);
			if (i == 2)
				m_val->color_b = ft_atoi(line_item);
			i++;
			line_item = strtok_r(tmp, ",", &tmp);
		}
		if (i != 3 || m_val->color_r < 0 || m_val->color_r > 255
			|| m_val->color_g < 0 || m_val->color_g > 255
			|| m_val->color_b < 0 || m_val->color_b > 255)
			return (-1);
		m_val->r_color = rgb(m_val->color_r, m_val->color_g, m_val->color_b);
	}
	return (1);
}
