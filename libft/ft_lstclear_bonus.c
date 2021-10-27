/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:18:11 by rlinkov           #+#    #+#             */
/*   Updated: 2019/10/25 17:55:44 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && del)
		if (*lst)
		{
			ft_lstclear(&(*lst)->next, del);
			ft_lstdelone(*lst, del);
			*lst = NULL;
		}
}
