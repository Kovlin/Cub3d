/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:01:25 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/26 19:27:53 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_step_dist(t_ray *r, t_game *game)
{
	double pos_x;
	double pos_y;

	pos_x = game->cube->player->pos[X];
	pos_y = game->cube->player->pos[Y];
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - pos_y) * r->delta_dist_y;
	}
}

void	init_ray(t_ray *ray, t_game *game)
{
	ray->h = game->cube->res[Y];
	ray->cam_x = ((2 * ray->col) / (double)ray->w) - 1.0;
	ray->ray_dir_x = game->cube->player->view[X]
		+ (game->cube->player->plane[X] * ray->cam_x);
	ray->ray_dir_y = game->cube->player->view[Y]
		+ (game->cube->player->plane[Y] * ray->cam_x);
	ray->map_x = game->cube->player->pos[X];
	ray->map_y = game->cube->player->pos[Y];
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	set_step_dist(ray, game);
}

void	ray_to_wall(t_ray *r, t_game *game)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			if (r->step_x == -1)
				r->side = 0;
			else
				r->side = 1;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			if (r->step_y == -1)
				r->side = 2;
			else
				r->side = 3;
		}
		if (game->cube->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	perp_wall_dist_calc(t_ray *r, t_game *game)
{
	double pos_x;
	double pos_y;

	pos_x = game->cube->player->pos[X];
	pos_y = game->cube->player->pos[Y];
	if (r->side == 0 || r->side == 1)
		r->perp_wall_dist = ((r->map_x - pos_x)
				+ ((1 - r->step_x) / 2)) / r->ray_dir_x;
	else
		r->perp_wall_dist = ((r->map_y - pos_y)
				+ ((1 - r->step_y) / 2)) / r->ray_dir_y;
	r->line_height = (int)(r->h / r->perp_wall_dist);
}

int		raycasting(t_game *game)
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		handle_error(ERR_MALLOC);
	ray->w = game->cube->res[X];
	ray->col = 0;
	if (!(ray->z_buff = malloc(ray->w * sizeof(double))))
		handle_error(ERR_MALLOC);
	while (ray->col < ray->w)
	{
		init_ray(ray, game);
		ray_to_wall(ray, game);
		perp_wall_dist_calc(ray, game);
		ray->z_buff[ray->col] = ray->perp_wall_dist;
		draw(ray, game);
		ray->col++;
	}
	handle_sprites(ray, game);
	free(ray);
	if (game->cube->info_save == 1)
		bmp_create(game);
	if (game->cube->info_save == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	clear_img(game);
	return (0);
}
