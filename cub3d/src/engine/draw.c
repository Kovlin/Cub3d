/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:35:52 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 18:34:54 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_and_ceiling(int i, int d_start, int d_end, t_game *g)
{
	int color_c;
	int color_f;
	int start;

	color_c = create_trgb(0, g->cube->color[CEILING][R],
			g->cube->color[CEILING][G], g->cube->color[CEILING][B]);
	color_f = create_trgb(0, g->cube->color[FLOOR][R],
			g->cube->color[FLOOR][G], g->cube->color[FLOOR][B]);
	start = 0;
	while (start < d_start)
	{
		my_mlx_pixel_put(g->img, i, start, color_c);
		start++;
	}
	start = d_end + 1;
	while (start < g->cube->res[Y])
	{
		my_mlx_pixel_put(g->img, i, start, color_f);
		start++;
	}
}

void	draw(t_ray *r, t_game *game)
{
	int draw_end;
	int draw_start;

	draw_start = -(r->line_height / 2) + (r->h / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (r->line_height / 2) + (r->h / 2);
	if (draw_end >= r->h)
		draw_end = r->h - 1;
	r->draw_start = draw_start;
	r->draw_end = draw_end;
	draw_texture(r, game);
	draw_floor_and_ceiling(r->col, draw_start, draw_end, game);
}
