/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:51:28 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 18:29:56 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite_y(t_ray *r, t_game *g, int i, int col)
{
	int				line;
	int				d;
	unsigned int	color;

	line = g->sprites[i].draw_start_y;
	while (line < g->sprites[i].draw_end_y)
	{
		d = (line) * 256 - r->h * 128 + g->sprites[i].sprite_height * 128;
		g->sprites[i].text_y = ((d * g->text[SPRITE].height)
				/ g->sprites[i].sprite_height) / 256;
		color = *(unsigned int*)(g->text[SPRITE].addr +
				(g->sprites[i].text_y * g->text[SPRITE].line_length)
				+ (g->sprites[i].text_x
				* (g->text[SPRITE].bits_per_pixel / 8)));
		if ((color & (0xFF << 24)) == 0)
		{
			*(unsigned int*)(g->img->addr + (line * g->img->line_length)
					+ (col * (g->img->bits_per_pixel / 8))) = color;
		}
		line++;
	}
}

void	draw_sprites(t_ray *r, t_game *g)
{
	int i;
	int col;

	i = 0;
	while (i < g->cube->nbr_sprites)
	{
		col = g->sprites[i].draw_start_x;
		while (col < g->sprites[i].draw_end_x)
		{
			g->sprites[i].text_x = (int)(256 * (col -
			(-g->sprites[i].sprite_width / 2
			+ g->sprites[i].sprite_screen_x))
			* g->text[SPRITE].width / g->sprites[i].sprite_width) / 256;
			if (g->sprites[i].trans_y > 0 && col > 0 && col < r->w &&
					g->sprites[i].trans_y < r->z_buff[col])
			{
				draw_sprite_y(r, g, i, col);
			}
			col++;
		}
		i++;
	}
}
