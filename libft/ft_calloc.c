/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:47:49 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/23 18:20:26 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated_area;
	size_t	total;

	total = size * count;
	allocated_area = malloc(total);
	if (!allocated_area)
		return (0);
	return (ft_memset(allocated_area, 0, total));
}
