/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:51:29 by rlinkov           #+#    #+#             */
/*   Updated: 2019/11/08 17:37:09 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_white_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	number;
	int				signe;

	signe = 1;
	number = 0;
	while (ft_is_white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	if (signe == -1 && number > 2147483648)
		return (0);
	else if (signe == 1 && number > 2147483647)
		return (-1);
	return ((int)number * signe);
}
