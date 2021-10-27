/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:32:21 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/16 15:59:14 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dsttemp;
	const char	*srctemp;

	if (src == dst)
		return (dst);
	dsttemp = dst;
	srctemp = src;
	if (dst != NULL || src != NULL)
	{
		if (srctemp <= dsttemp)
		{
			dsttemp += len - 1;
			srctemp += len - 1;
			while (len > 0)
			{
				*dsttemp = *srctemp;
				len--;
				dsttemp--;
				srctemp--;
			}
		}
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
