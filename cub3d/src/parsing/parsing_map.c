/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 10:26:42 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/25 19:04:35 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_elem(char *line, t_cube *cube)
{
	while (*line == ' ')
		line++;
	if (ft_memcmp(line, "NO ", 3) == 0)
		store_elem_texture(cube, line, NORTH);
	else if (ft_memcmp(line, "SO ", 3) == 0)
		store_elem_texture(cube, line, SOUTH);
	else if (ft_memcmp(line, "EA ", 3) == 0)
		store_elem_texture(cube, line, EAST);
	else if (ft_memcmp(line, "WE ", 3) == 0)
		store_elem_texture(cube, line, WEST);
	else if (ft_memcmp(line, "S ", 2) == 0)
		store_elem_texture(cube, line, SPRITE);
	else if (ft_memcmp(line, "F ", 2) == 0)
		store_elem_color(cube, line, FLOOR);
	else if (ft_memcmp(line, "C ", 2) == 0)
		store_elem_color(cube, line, CEILING);
	else if (ft_memcmp(line, "R ", 2) == 0)
		store_elem_res(cube, line, RES);
	else
		handle_error(ERR_ELEM_FORM);
	return (0);
}

void	handle_elements(t_cube *cube, char *line, int fd)
{
	int ret;
	int nb_elem;
	int i;

	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		i = -1;
		nb_elem = 0;
		while (++i < NB_ELEM)
			nb_elem += cube->e_count[i];
		if (*line != '\0')
		{
			if (nb_elem < NB_ELEM)
				check_elem(line, cube);
			else
			{
				handle_map(cube, line, fd);
				break ;
			}
		}
		free(line);
		if (ret == 0)
			break ;
	}
}

void	parsing_map(t_cube *cube, char *path)
{
	int		fd;
	char	*line;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		close(fd);
		handle_error(ERR_FILE_OP);
	}
	line = NULL;
	handle_elements(cube, line, fd);
}
