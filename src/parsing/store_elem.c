/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:03:06 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/26 16:25:58 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		contain_illegal_char(char *str)
{
	int check;

	check = 0;
	while (*str != '\0' && *str == ' ')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
	{
		check = 1;
		str++;
	}
	if (check == 0)
		return (1);
	while (*str != '\0')
	{
		if (*str != ' ')
			return (1);
		str++;
	}
	return (0);
}

void	store_elem_color(t_cube *cube, char *line, int tag)
{
	int		i;
	char	**color_stock;

	cube->e_count[tag + DECAL]++;
	if (cube->e_count[tag + DECAL] != 1)
		handle_error(ERR_ELEM_NBR);
	line += 2;
	color_stock = ft_split(line, ',');
	i = 0;
	while (color_stock[i] != 0)
		i++;
	if (i != 3 || (line[(int)ft_strlen(line) - 1] == ','))
		handle_error(ERR_ELEM_CLR);
	i = 0;
	while (i < 3)
	{
		if (contain_illegal_char(color_stock[i]) == 1)
			handle_error(ERR_ELEM_CLR);
		cube->color[tag][i] = ft_atoi(color_stock[i]);
		if (cube->color[tag][i] > 255 || cube->color[tag][i] < 0)
			handle_error(ERR_ELEM_CLR);
		free(color_stock[i]);
		i++;
	}
	free(color_stock);
}

void	store_elem_res(t_cube *cube, char *line, int tag)
{
	int		i;
	char	**res_stock;

	cube->e_count[tag]++;
	if (cube->e_count[tag] != 1)
		handle_error(ERR_ELEM_NBR);
	line += 2;
	res_stock = ft_split(line, ' ');
	i = 0;
	while (res_stock[i] != 0)
		i++;
	if (i != 2)
		handle_error(ERR_ELEM_RES);
	i = 0;
	while (i < 2)
	{
		if (contain_illegal_char(res_stock[i]) == 1)
			handle_error(ERR_ELEM_RES);
		cube->res[i] = ft_atoi(res_stock[i]);
		if (cube->res[i] <= 0)
			handle_error(ERR_ELEM_RES);
		free(res_stock[i]);
		i++;
	}
	free(res_stock);
}

void	check_text_path(t_cube *cube, int tag)
{
	int fd;

	if ((fd = open(cube->textures[tag], O_RDONLY)) < 0)
		handle_error(ERR_TEXT_PATH);
	close(fd);
}

void	store_elem_texture(t_cube *cube, char *line, int tag)
{
	cube->e_count[tag]++;
	if (cube->e_count[tag] != 1)
		handle_error(ERR_ELEM_NBR);
	line += 2;
	if (tag != SPRITE)
		line++;
	while (*line == ' ')
		line++;
	cube->textures[tag] = (char*)malloc((int)ft_strlen(line) + 1);
	if ((int)ft_strlen(line) <= 1)
		handle_error(ERR_FORM_CUB);
	else
		ft_memcpy(cube->textures[tag], line, (int)ft_strlen(line));
	cube->textures[tag][(int)ft_strlen(line)] = '\0';
	check_text_path(cube, tag);
}
