/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:07:15 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 19:11:10 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_error(char *err_tag)
{
	ft_putstr_fd(RED, 1);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(err_tag, 1);
	ft_putstr_fd(RESET, 1);
	exit(EXIT_FAILURE);
}

void	setup_screen_size(t_game *game)
{
	int sizex;
	int sizey;

	mlx_get_screen_size(game->mlx, &sizex, &sizey);
	if (game->cube->res[X] > sizex)
		game->cube->res[X] = sizex;
	if (game->cube->res[Y] > sizey)
		game->cube->res[Y] = sizey;
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	clear_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img);
	game->img->img =
	mlx_new_image(game->mlx, game->cube->res[X], game->cube->res[Y]);
	game->img->addr =
	mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
			&game->img->line_length, &game->img->endian);
}
