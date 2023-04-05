/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:52:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/03 21:54:03 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int main()
// {
//     t_list *head;
//     t_list *one;
//     t_list *two;

//     head = ft_lstnew((void*)4);
//     one = ft_lstnew((void*)5);
//     two = ft_lstnew((void*)6);

//     ft_lstadd_front(&head, one);
//     ft_lstadd_front(&head, two);

//     printf("%ld\n", (uintptr_t)ft_lstlast(head)-> content);
// }
