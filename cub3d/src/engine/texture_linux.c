/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:14:38 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/25 20:28:32 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			select_texture(t_ray *r)
{
	if (r->side == 0)
		return (EAST);
	else if (r->side == 1)
		return (WEST);
	else if (r->side == 2)
		return (SOUTH);
	else
		return (NORTH);
}

void		init_text_col(t_ray *r, t_game *game)
{
	int	text;

	text = select_texture(r);
	if (r->side < 2)
		r->wall_x = game->cube->player->pos[Y] +
			(r->perp_wall_dist * r->ray_dir_y);
	else
		r->wall_x = game->cube->player->pos[X] +
			(r->perp_wall_dist * r->ray_dir_x);
	r->wall_x -= floor((r->wall_x));
	r->text_x = (int)(r->wall_x * (double)game->text[text].width);
	if (r->side < 2 && r->ray_dir_x > 0)
		r->text_x = game->text[text].width - r->text_x - 1;
	if (r->side >= 2 && r->ray_dir_y < 0)
		r->text_x = game->text[text].width - r->text_x - 1;
}

void		draw_texture(t_ray *r, t_game *game)
{
	double	step;
	double	tex_pos;
	int		y;
	int		text;

	text = select_texture(r);
	init_text_col(r, game);
	step = 1.0 * game->text[text].height / r->line_height;
	tex_pos = (r->draw_start - (r->h / 2) + (r->line_height / 2)) * step;
	y = r->draw_start;
	while (y <= r->draw_end)
	{
		r->text_y = (int)tex_pos & (game->text[text].height - 1);
		*(unsigned int*)(game->img->addr + (y * game->img->line_length)
				+ (r->col * (game->img->bits_per_pixel / 8))) =
			*(unsigned int*)(game->text[text].addr +
					(r->text_y * game->text[text].line_length)
					+ (r->text_x * (game->text[text].bits_per_pixel / 8)));
		y++;
		tex_pos += step;
	}
}

void		load_texture(t_game *g)
{
	int	i;

	i = 0;
	while (i < NB_TEXT)
	{
		if (!(g->text[i].img = mlx_xpm_file_to_image(g->mlx,
		g->cube->textures[i], &g->text[i].width, &g->text[i].height)))
			handle_error(ERR_EXT_TEX);
		g->text[i].addr = mlx_get_data_addr(g->text[i].img,
		&g->text[i].bits_per_pixel
		, &g->text[i].line_length, &g->text[i].endian);
		i++;
	}
}
