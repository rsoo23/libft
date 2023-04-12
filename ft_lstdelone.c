/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:04:20 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/12 10:49:24 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst-> content);
	free(lst);
}

// void    ft_del(void* content)
// {
//     free(content);
// }

// int main()
// {
//     t_list *lst = ft_lstnew((void*)3);    
//     t_list *one = ft_lstnew((void*)4);    
//     t_list *two = ft_lstnew((void*)5);

//     ft_lstadd_back(&lst, one);
//     ft_lstadd_back(&lst, two);

//     ft_lstdelone(one, ft_del);

//     while (lst)
//     {
//         printf("%ld\n", (uintptr_t)lst-> content);
//         lst = lst-> next;
//     }
// }