/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:13:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/14 23:13:07 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *temp;
    while (*lst)
    {
        temp = *lst;
        *lst = *lst-> next;
        del(temp-> content);
        free(temp);
    }
    *lst = NULL;
}
