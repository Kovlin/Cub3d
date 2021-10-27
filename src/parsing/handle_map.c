/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:01:37 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/25 19:46:40 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocate_map(char *line, t_cube *cube, int index)
{
	char	**tmp_map;
	int		i;

	tmp_map = (char**)malloc((index + 1) * sizeof(char*));
	i = 0;
	while (i < index)
	{
		if (!(tmp_map[i] = malloc((int)ft_strlen(cube->map[i]) + 1)))
			handle_error(ERR_MALLOC);
		ft_memcpy(tmp_map[i], cube->map[i], ft_strlen(cube->map[i]));
		tmp_map[i][ft_strlen(cube->map[i])] = '\0';
		free(cube->map[i]);
		i++;
	}
	if (!(tmp_map[index] = malloc((int)ft_strlen(line) + 1)))
		handle_error(ERR_MALLOC);
	ft_memcpy(tmp_map[i], line, ft_strlen(line));
	tmp_map[index][(int)ft_strlen(line)] = '\0';
	free(cube->map);
	cube->map = tmp_map;
}

void	check_illegal_char(t_cube *cube)
{
	int i;
	int j;
	int check;

	i = -1;
	check = 0;
	while (++i < cube->map_height)
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != '0'
					&& cube->map[i][j] != '2' && cube->map[i][j] != ' ')
			{
				if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
						|| cube->map[i][j] == 'E' || cube->map[i][j] == 'W')
					check++;
				else
					handle_error(ERR_MAP);
			}
			j++;
		}
	}
	if (check != 1)
		handle_error(ERR_MAP_CHAR_NF);
}

int		valid(t_cube *cube, int k, int l)
{
	int len;

	if (k >= 0 && k < cube->map_height)
		len = ft_strlen(cube->map[k]);
	else
		return (0);
	if (l >= len || l < 0)
		return (0);
	if (cube->map[k][l] == ' ')
		return (0);
	return (1);
}

void	check_map_validity(t_cube *cube)
{
	int i;
	int j;

	i = 0;
	while (i < cube->map_height)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != ' ')
			{
				if (!valid(cube, i + 1, j) || !(valid(cube, i - 1, j)))
					handle_error(ERR_MAP);
				if (!valid(cube, i, j - 1) || !(valid(cube, i, j + 1)))
					handle_error(ERR_MAP);
			}
			if (cube->map[i][j] == '2')
				cube->nbr_sprites++;
			j++;
		}
		i++;
	}
}

void	handle_map(t_cube *cube, char *line, int fd)
{
	int ret;
	int i;

	if (!(cube->map[0] = (char*)malloc((int)(ft_strlen(line) + 1))))
		handle_error(ERR_MALLOC);
	ft_memcpy(cube->map[0], line, ft_strlen(line) + 1);
	i = 1;
	free(line);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (*line == '\0')
			handle_error(ERR_MAP);
		else
			allocate_map(line, cube, i);
		free(line);
		if (ret == 0)
			break ;
		i++;
	}
	cube->map_height = i + 1;
	check_illegal_char(cube);
	check_map_validity(cube);
}
