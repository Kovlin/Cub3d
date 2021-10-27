/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:31:36 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/10 16:56:30 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dsttemp;
	unsigned const char	*srctemp;

	dsttemp = dst;
	srctemp = src;
	while (n > 0)
	{
		*dsttemp = *srctemp;
		if (*srctemp == (unsigned char)c)
			return (dsttemp + 1);
		dsttemp++;
		srctemp++;
		n--;
	}
	return (NULL);
}
