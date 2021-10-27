/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:25:35 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/25 20:35:16 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_cube *cube)
{
	if (!(cube->color = (int**)malloc(2 * sizeof(int*))))
		handle_error(ERR_MALLOC);
	if (!(cube->color[0] = (int*)(malloc(3 * sizeof(int)))))
		handle_error(ERR_MALLOC);
	if (!(cube->color[1] = (int*)(malloc(3 * sizeof(int)))))
		handle_error(ERR_MALLOC);
	if (!(cube->res = (int*)malloc(2 * sizeof(int))))
		handle_error(ERR_MALLOC);
	cube->res[0] = 0;
	cube->res[1] = 0;
	if (!(cube->map = malloc(sizeof(char*))))
		handle_error(ERR_MALLOC);
	if (!(cube->player = malloc(sizeof(t_player))))
		handle_error(ERR_MALLOC);
	cube->nbr_sprites = 0;
}

void	init_cube(t_cube *cube)
{
	int i;

	i = 0;
	if (!(cube->textures = (char**)malloc((int)NB_TEXT * sizeof(char*))))
		handle_error(ERR_MALLOC);
	if (!(cube->e_count = (int*)malloc(8 * sizeof(int))))
		handle_error(ERR_MALLOC);
	i = 0;
	while (i < 8)
	{
		cube->e_count[i] = 0;
		i++;
	}
	init(cube);
}
