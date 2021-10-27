/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:53:20 by rlinkov           #+#    #+#             */
/*   Updated: 2019/11/04 15:01:34 by rlinkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *temp;

	if (l && f && del)
	{
		if (!(new_lst = ft_lstnew(f(l->content))))
			return (NULL);
		while (l->next)
		{
			l = l->next;
			if (!(temp = ft_lstnew(f(l->content))))
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&new_lst, temp);
		}
		return (new_lst);
	}
	return (NULL);
}
