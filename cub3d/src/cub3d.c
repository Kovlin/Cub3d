/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <rlinkov@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:05:50 by rlinkov           #+#    #+#             */
/*   Updated: 2020/11/20 18:13:21 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	if (argc < 2)
		handle_error(ERR_FEW_ARGS);
	else if (argc > 3)
		handle_error(ERR_MUCH_ARGS);
	check_map_ext(argv[1]);
	if (argc == 3)
		check_sec_arg(argv[2]);
	run_process(argc, argv[1]);
	exit(EXIT_SUCCESS);
}
