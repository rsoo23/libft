/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:47:11 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/12 16:35:51 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void(*del)(void*))
{
	t_list	*new_lst;
	t_list	*temp;

	new_lst = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		temp = ft_lstnew(f(lst-> content));
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = lst-> next;
	}
	ft_lstadd_back(&new_lst, NULL);
	return (new_lst);
}
