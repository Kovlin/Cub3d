/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:26:19 by rlinkov           #+#    #+#             */
/*   Updated: 2019/11/08 19:32:44 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	size_str(int n)
{
	size_t size;

	size = 1;
	if (n < 0)
		size++;
	while ((n / 10) != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void		fill_str(char *str, int n, int index_max)
{
	unsigned int	number;

	if (n < 0)
	{
		number = (n * -1);
		str[0] = '-';
	}
	else
		number = n;
	if ((number / 10) != 0)
		fill_str(str, number / 10, index_max - 1);
	str[index_max] = (number % 10) + '0';
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	size_s;

	size_s = size_str(n);
	if (!(str = (char*)malloc((size_s + 1) * sizeof(char))))
		return (0);
	fill_str(str, n, size_s - 1);
	str[size_s] = '\0';
	return (str);
}
