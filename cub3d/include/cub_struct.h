/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 17:10:53 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 18:51:25 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct	s_player
{
	double		*pos;
	double		*view;
	double		*plane;
}				t_player;

typedef struct	s_cube3d
{
	int			**color;
	int			*res;
	char		**textures;
	int			*e_count;
	char		**map;
	int			map_height;
	int			nbr_sprites;
	int			info_save;
	t_player	*player;
}				t_cube;

typedef struct	s_sprites
{
	double		x;
	double		y;
	double		sprite_dist;
	double		pos_x;
	double		pos_y;
	double		inv_det;
	double		trans_x;
	double		trans_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			draw_start_y;
	int			draw_end_y;
	int			text_x;
	int			text_y;
}				t_sprites;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_data		*img;
	t_data		*text;
	t_cube		*cube;
	int			*keys;
	t_sprites	*sprites;
}				t_game;

typedef	struct	s_ray
{
	int			h;
	int			w;
	double		cam_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			text_x;
	int			text_y;
	int			col;
	double		*z_buff;
	int			hit;
}				t_ray;

#endif
