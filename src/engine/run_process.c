/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:27:02 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/26 18:27:24 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_win(t_game *g)
{
	(void)g;
	exit(EXIT_SUCCESS);
}

void	init_game(t_game *game)
{
	int i;

	game->mlx = mlx_init();
	setup_screen_size(game);
	if (!(game->keys = malloc(6 * sizeof(int))))
		handle_error(ERR_MALLOC);
	i = 0;
	while (i < KEYS)
	{
		game->keys[i] = 0;
		i++;
	}
	if (game->cube->info_save == 0)
		game->win = mlx_new_window(game->mlx, game->cube->res[X],
		game->cube->res[Y], "Cub3D");
	if (!(game->img = malloc(sizeof(t_data))))
		handle_error(ERR_MALLOC);
	if (!(game->text = malloc(5 * sizeof(t_data))))
		handle_error(ERR_MALLOC);
	game->img->img = mlx_new_image(game->mlx, game->cube->res[X],
			game->cube->res[Y]);
	game->img->addr = mlx_get_data_addr(game->img->img,
	&game->img->bits_per_pixel,
	&game->img->line_length, &game->img->endian);
}

void	start_cube(t_cube *cube)
{
	t_game	*game;

	init_player(cube);
	if (!(game = malloc(sizeof(t_game))))
		handle_error(ERR_MALLOC);
	game->cube = cube;
	init_game(game);
	load_texture(game);
	init_sprites(game);
	raycasting(game);
	handle_event(game);
}

void	run_process(int args, char *path)
{
	t_cube	*cube;

	if (!(cube = (t_cube*)malloc(sizeof(t_cube))))
		handle_error(ERR_MALLOC);
	init_cube(cube);
	parsing_map(cube, path);
	if (args == 3)
		cube->info_save = 1;
	else
		cube->info_save = 0;
	start_cube(cube);
	exit(0);
}
