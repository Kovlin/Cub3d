/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:03:34 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/26 18:05:59 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_file_header(t_data *img, int fd)
{
	int file_size;
	int pixel_data_offset;

	pixel_data_offset = 54;
	file_size = pixel_data_offset
	+ ((img->bits_per_pixel * img->height * img->width) / 8);
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0", 2);
	write(fd, "\0\0", 2);
	write(fd, &pixel_data_offset, 4);
}

void	bmp_img_header(t_game *g, int fd)
{
	int bi_planes;
	int img_header_size;
	int img_size;

	img_header_size = 40;
	bi_planes = 1;
	img_size = g->img->height * g->img->width;
	write(fd, &img_header_size, 4);
	write(fd, &g->cube->res[X], 4);
	write(fd, &g->cube->res[Y], 4);
	write(fd, &bi_planes, 2);
	write(fd, &g->img->bits_per_pixel, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

void	bmp_pixel_data(t_game *game, t_data *img, int fd)
{
	int x;
	int y;
	int r;
	int g;
	int b;

	y = game->cube->res[Y] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->cube->res[X])
		{
			r = img->addr[y * img->line_length + x * img->bits_per_pixel / 8];
			g = img->addr[y * img->line_length +
			x * img->bits_per_pixel / 8 + 1];
			b = img->addr[y * img->line_length +
			x * img->bits_per_pixel / 8 + 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
			x++;
		}
		y--;
	}
}

void	bmp_create(t_game *game)
{
	int	fd;

	if ((fd = open("screenshot.bmp", O_CREAT
	| O_WRONLY, 0777)) < 0)
		handle_error(ERR_BMP);
	bmp_file_header(game->img, fd);
	bmp_img_header(game, fd);
	bmp_pixel_data(game, game->img, fd);
	close(fd);
	exit(EXIT_SUCCESS);
}
