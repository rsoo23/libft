/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:47:11 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/14 23:47:11 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  ft_lstmap(t_list *lst, void *(*f)(void*), void(*del)(void*))
{
    t_list  *new_lst;
    t_list  *temp;

    while (lst)
    {
        if (!(temp = ft_lstnew(f(lst-> content))))
        {
            del(lst-> content);
            return (0);
        }
        ft_lstadd_back(&new_lst, temp);
        lst = lst-> next;
    }
    return (new_lst);
}