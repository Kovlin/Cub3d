/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:01:47 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 17:49:25 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_n_s(t_cube *cube, int i, int j)
{
	if (cube->map[i][j] == 'N')
	{
		cube->player->view[X] = 0.0;
		cube->player->view[Y] = -1.0;
		cube->player->plane[X] = 0.66;
		cube->player->plane[Y] = 0;
	}
	else if (cube->map[i][j] == 'S')
	{
		cube->player->view[X] = 0;
		cube->player->view[Y] = 1;
		cube->player->plane[X] = -0.66;
		cube->player->plane[Y] = 0;
	}
}

void	init_player_e_w(t_cube *cube, int i, int j)
{
	if (cube->map[i][j] == 'E')
	{
		cube->player->view[X] = 1;
		cube->player->view[Y] = 0;
		cube->player->plane[X] = 0;
		cube->player->plane[Y] = 0.66;
	}
	else if (cube->map[i][j] == 'W')
	{
		cube->player->view[X] = -1;
		cube->player->view[Y] = 0;
		cube->player->plane[X] = 0;
		cube->player->plane[Y] = -0.66;
	}
}

int		init_player_status(t_cube *cube, int i, int j)
{
	if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S')
		init_player_n_s(cube, i, j);
	else if (cube->map[i][j] == 'E' || cube->map[i][j] == 'W')
		init_player_e_w(cube, i, j);
	else
		return (0);
	cube->map[i][j] = '0';
	cube->player->pos[X] = j + 0.5;
	cube->player->pos[Y] = i + 0.5;
	return (1);
}

void	init_player(t_cube *cube)
{
	int i;
	int j;
	int ret;

	if (!(cube->player->pos = (double*)malloc(2 * sizeof(double))))
		handle_error(ERR_MALLOC);
	if (!(cube->player->view = (double*)malloc(2 * sizeof(double))))
		handle_error(ERR_MALLOC);
	if (!(cube->player->plane = (double*)malloc(2 * sizeof(double))))
		handle_error(ERR_MALLOC);
	i = 0;
	ret = 0;
	j = 0;
	while ((i < cube->map_height) && ret == 0)
	{
		j = 0;
		while (cube->map[i][j] && ret == 0)
		{
			ret = init_player_status(cube, i, j);
			j++;
		}
		i++;
	}
}
