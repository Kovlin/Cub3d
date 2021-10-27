/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:09:58 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/10 17:17:27 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dst);
	if (size < size_dest)
	{
		return (size_src + size);
	}
	else
	{
		dst += size_dest;
		size -= size_dest;
		while (*src != '\0' && size > 1)
		{
			*dst = *src;
			src++;
			dst++;
			size--;
		}
		*dst = '\0';
	}
	return (size_dest + size_src);
}
