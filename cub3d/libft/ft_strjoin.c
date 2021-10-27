/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:21:25 by rlinkov           #+#    #+#             */
/*   Updated: 2019/11/08 17:59:47 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size1;
	size_t	size2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(str = (char *)malloc((size1 + size2 + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(str, s1, size1);
	ft_memcpy(str + size1, s2, size2 + 1);
	return (str);
}
