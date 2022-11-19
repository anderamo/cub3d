/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:14:35 by aamorin-          #+#    #+#             */
/*   Updated: 2022/11/18 16:58:42 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
#include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

# include <stdint-gcc.h>
# define FILE_EXTENSION ".cub"
# define NO_STR_SEARCH "NO"
# define SO_STR_SEARCH "SO"
# define EA_STR_SEARCH "EA"
# define WE_STR_SEARCH "WE"
# define ROOF_STR_SEARCH "C"
# define FLOOR_STR_SEARCH "F"

typedef struct s_data{
	void	*i_ptr;
	char	*addr;
	int		b_pixel;
	int		l_len;
	int		i_w;
	int		i_h;
	int		endian;
}			t_data;

typedef struct s_map {
	t_data	img;
	t_data	pov;
	t_data	pov_shot;
	t_data	wall[4];
	int		fd;
	int		color_r;
	int		color_g;
	int		color_b;
	long	r_color;
	long	f_color;
	char	*no_str;
	char	*ea_str;
	char	*we_str;
	char	*so_str;
	char	*floor_str;
	char	*roof_str;
	char	**map;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*w_ptr;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planey;
	double	planex;
	double	rot;
	double	move;
	bool	fwd;
	bool	bwd;
	bool	left;
	bool	right;
}		t_map;

typedef struct s_create_map {
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		wall_type;
	double	wallx;
	double	step;
	double	texpos;
	uint8_t	color[4];
	int		texy;
	int		texx;
	int		lineheight;
	int		drawstart;
	int		drawend;
}		t_create_map;

typedef struct s_check_map {
	int		y;
	int		x;
	char	c;
	char	last_char;
}		t_check_map;

int				c_file(char *str);
int				RGB(int r, int g, int b);
void			print_map(char **map);
int				get_no_str(t_map *m_val, char *line_item, char **tmp_line);
int				get_ea_str(t_map *m_val, char *line_item, char **tmp_line);
int				get_we_str(t_map *m_val, char *line_item, char **tmp_line);
int				get_so_str(t_map *m_val, char *line_item, char **tmp_line);
int				get_floor_str(t_map *m_val, char *line_item, char **tmp_line);
int				get_roof_str(t_map *m_val, char *line_item, char **tmp_line);
t_create_map	init_ray_struct(t_create_map ray, t_map *m_val, int x);
t_map			*init_new_map_struct(void);
void			p_map(t_map	*m_val, char **tmp_line,
					char **line, char *line_item);
int				p_file(t_map *m_val, char *file_str,
					char *line_item, char *line);
int				parse_return(char *line);
void			move_player_back(t_map	*m);
void			move_player_forward(t_map	*m);
void			move_player_left(t_map *m);
void			move_player_rigth(t_map *m);
int				move_player(void *param);
int				key_release_manager(int keycode, void *param);
int				key_press_manager(int keycode, void *param);
int				close_win_x(t_map *vars);
int				create_map(t_map *m_val, int i, int x);
int				create_f_colors(t_map *m_val, uint8_t i);
int				create_r_colors(t_map *m_val, uint8_t i);
int				c_file(char *file_str);
int				check_is_empty_line(char *file_str);
t_create_map	hit(t_create_map ray, t_map *m_val);
t_create_map	how_much_draw(t_create_map ray, t_map *m_val);
t_create_map	put_texturize_pos_color(t_create_map ray, t_map *m_val, int x);
t_create_map	determine_position(t_create_map ray, t_map *m_val);
int				texturize_walls(t_map *map, uint8_t i);
int				rgb(int r, int g, int b);
int				destroy_map_struct(t_map *m_val);
t_create_map	put_texturize_pos_color(t_create_map ray, t_map *m_val, int x);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				check_map(t_map *m, int heigth, int width, t_check_map c);
void			n_e_w_s_2(t_map *m, int y, int x);
int				n_e_w_s(t_map *m, t_check_map check);

#endif