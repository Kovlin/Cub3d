/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:06:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/25 19:58:02 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites(t_game *g)
{
	int i;
	int nbr;
	int j;
	int s;

	nbr = g->cube->nbr_sprites;
	if (!(g->sprites = malloc(nbr * sizeof(t_sprites))))
		handle_error(ERR_MALLOC);
	i = 0;
	s = 0;
	while (i < g->cube->map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(g->cube->map[i]))
		{
			if (g->cube->map[i][j] == '2')
			{
				g->sprites[s].x = j;
				g->sprites[s].y = i;
				s++;
			}
			j++;
		}
		i++;
	}
}

void	order_sprites(t_game *g)
{
	int			i;
	int			j;
	t_sprites	temp;

	i = 0;
	while (i < g->cube->nbr_sprites - 1)
	{
		j = i + 1;
		while (j < g->cube->nbr_sprites)
		{
			if (g->sprites[i].sprite_dist < g->sprites[j].sprite_dist)
			{
				temp = g->sprites[i];
				g->sprites[i] = g->sprites[j];
				g->sprites[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sprite_init_value(t_ray *r, t_game *g, int i)
{
	g->sprites[i].pos_x = g->sprites[i].x - g->cube->player->pos[X] + 0.5;
	g->sprites[i].pos_y = g->sprites[i].y - g->cube->player->pos[Y] + 0.5;
	g->sprites[i].inv_det = 1.0 / (g->cube->player->plane[X]
			* g->cube->player->view[Y]
			- g->cube->player->view[X] * g->cube->player->plane[Y]);
	g->sprites[i].trans_x = g->sprites[i].inv_det
		* (g->cube->player->view[Y] * g->sprites[i].pos_x
				- g->cube->player->view[X] * g->sprites[i].pos_y);
	g->sprites[i].trans_y = g->sprites[i].inv_det
		* (-g->cube->player->plane[Y] * g->sprites[i].pos_x
				+ g->cube->player->plane[X] * g->sprites[i].pos_y);
	g->sprites[i].sprite_screen_x = (int)((r->w / 2)
			* (1 + g->sprites[i].trans_x / g->sprites[i].trans_y));
	g->sprites[i].sprite_height = abs((int)(r->h / g->sprites[i].trans_y));
	g->sprites[i].sprite_width = abs((int)(r->h / g->sprites[i].trans_y));
}

void	sprite_draw_value(t_ray *r, t_game *g, int i)
{
	g->sprites[i].draw_start_y = (-g->sprites[i].sprite_height / 2)
		+ (r->h / 2);
	if (g->sprites[i].draw_start_y < 0)
		g->sprites[i].draw_start_y = 0;
	g->sprites[i].draw_end_y = (g->sprites[i].sprite_height / 2)
		+ (r->h / 2);
	if (g->sprites[i].draw_end_y >= r->h)
		g->sprites[i].draw_end_y = r->h - 1;
	g->sprites[i].draw_start_x = (-g->sprites[i].sprite_width / 2)
		+ g->sprites[i].sprite_screen_x;
	if (g->sprites[i].draw_start_x < 0)
		g->sprites[i].draw_start_x = 0;
	g->sprites[i].draw_end_x = (g->sprites[i].sprite_width / 2)
		+ g->sprites[i].sprite_screen_x;
	if (g->sprites[i].draw_end_x >= r->w)
		g->sprites[i].draw_end_x = r->w - 1;
}

void	handle_sprites(t_ray *r, t_game *g)
{
	int i;

	if (g->cube->nbr_sprites > 0)
	{
		i = 0;
		while (i < g->cube->nbr_sprites)
		{
			g->sprites[i].sprite_dist =
			((g->cube->player->pos[X] - g->sprites[i].x)
			* (g->cube->player->pos[X] - g->sprites[i].x)
			+ (g->cube->player->pos[Y] - g->sprites[i].y)
			* (g->cube->player->pos[Y] - g->sprites[i].y));
			i++;
		}
		order_sprites(g);
		i = 0;
		while (i < g->cube->nbr_sprites)
		{
			sprite_init_value(r, g, i);
			sprite_draw_value(r, g, i);
			i++;
		}
		draw_sprites(r, g);
	}
	free(r->z_buff);
}
