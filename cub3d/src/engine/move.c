/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:40:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 18:44:20 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_up(t_game *g)
{
	float	p_x;
	float	p_y;
	float	v_x;
	float	v_y;

	p_x = g->cube->player->pos[X];
	p_y = g->cube->player->pos[Y];
	v_x = g->cube->player->view[X];
	v_y = g->cube->player->view[Y];
	if (g->cube->map[(int)(p_y + (v_y * SPEED))][(int)(p_x)] == '0')
	{
		g->cube->player->pos[Y] += (v_y * SPEED);
		p_y = g->cube->player->pos[Y];
	}
	if (g->cube->map[(int)(p_y)][(int)(p_x + (v_x * SPEED))] == '0')
		g->cube->player->pos[X] += (v_x * SPEED);
}

void		move_down(t_game *g)
{
	double	p_x;
	double	p_y;
	double	v_x;
	double	v_y;

	p_x = g->cube->player->pos[X];
	p_y = g->cube->player->pos[Y];
	v_x = g->cube->player->view[X];
	v_y = g->cube->player->view[Y];
	if (g->cube->map[(int)(p_y - (v_y * SPEED))][(int)p_x] == '0')
	{
		g->cube->player->pos[Y] -= (v_y * SPEED);
		p_y = g->cube->player->pos[Y];
	}
	if (g->cube->map[(int)p_y][(int)(p_x - (v_x * SPEED))] == '0')
		g->cube->player->pos[X] -= (v_x * SPEED);
}

void		move_right(t_game *g)
{
	double	p_x;
	double	p_y;
	double	plan_x;
	double	plan_y;

	p_x = g->cube->player->pos[X];
	p_y = g->cube->player->pos[Y];
	plan_x = g->cube->player->plane[X];
	plan_y = g->cube->player->plane[Y];
	if (g->cube->map[(int)(p_y + (plan_y * SPEED))][(int)p_x] == '0')
	{
		g->cube->player->pos[Y] += (plan_y * SPEED);
		p_y = g->cube->player->pos[Y];
	}
	if (g->cube->map[(int)p_y][(int)(p_x + (plan_x * SPEED))] == '0')
		g->cube->player->pos[X] += (plan_x * SPEED);
}

void		move_left(t_game *g)
{
	double	p_x;
	double	p_y;
	double	plan_x;
	double	plan_y;

	p_x = g->cube->player->pos[X];
	p_y = g->cube->player->pos[Y];
	plan_x = g->cube->player->plane[X];
	plan_y = g->cube->player->plane[Y];
	if (g->cube->map[(int)(p_y - (plan_y * SPEED))][(int)p_x] == '0')
	{
		g->cube->player->pos[Y] -= (plan_y * SPEED);
		p_y = g->cube->player->pos[Y];
	}
	if (g->cube->map[(int)p_y][(int)(p_x - (plan_x * SPEED))] == '0')
		g->cube->player->pos[X] -= (plan_x * SPEED);
}
