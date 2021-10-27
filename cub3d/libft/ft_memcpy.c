/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:17:10 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/15 18:44:03 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dsttemp;
	const unsigned char	*srctemp;

	if (src == dst)
		return (dst);
	dsttemp = dst;
	srctemp = src;
	while (n > 0 && (dst != NULL || src != NULL))
	{
		*dsttemp = *srctemp;
		dsttemp++;
		srctemp++;
		n--;
	}
	return (dst);
}
