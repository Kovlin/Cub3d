/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:09:23 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/15 15:13:47 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t len2;

	if ((!s1 || !s2) && !n)
		return (0);
	len = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	if (len >= len2)
	{
		if (len2 < n)
			return (ft_memcmp(s1, s2, len2));
	}
	else
	{
		if (len < n)
			return (ft_memcmp(s1, s2, len));
	}
	return (ft_memcmp(s1, s2, n));
}
