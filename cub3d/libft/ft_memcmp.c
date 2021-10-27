/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:47:59 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/08 17:59:16 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *temp1;
	const unsigned char *temp2;

	temp1 = s1;
	temp2 = s2;
	while (n > 0)
	{
		if (*temp1 != *temp2)
		{
			return (*temp1 - *temp2);
		}
		else
		{
			temp1++;
			temp2++;
		}
		n--;
	}
	return (0);
}
