/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:25:23 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// *lst = new: sets the 'starting point' of the linked lists as new

// int main()
// {
//     t_list *lst = NULL;
//     t_list *new = NULL;

//     lst = ft_lstnew((void*)34);

//     new = ft_lstnew((void*)22);
//     ft_lstadd_front(&lst, new);

//     printf("List contents:");
//     while (lst)
//     {
//         printf("%ld", (uintptr_t)lst-> content);
//         lst = lst-> next;
//     }
//     printf("\n");
// }

// Params:
// 1. address of pointer to the first link of a list
// 2. address of pointer to the element to be added 
//    to the list

// the second line updates the new elem / node as the new
// head of the list

// A t_list **lst argument is used in the ft_lstadd_front function 
// because it allows the function to modify the original pointer to 
// the head of the list.
// In C, function arguments are passed by value, meaning that the function
// receives a copy of the argument, not the original argument itself. If 
// we were to pass a pointer to the head of the list directly (t_list *lst), 
// the function would receive a copy of that pointer, and any changes made to 
// the pointer within the function would only affect the copy, not the original 
// pointer.
// By passing a pointer to a pointer (t_list **lst), the function receives the 
// address of the original pointer. This allows the function to modify the 
// original pointer by dereferencing the pointer-to-pointer (*lst) and setting 
// it to a new value (i.e., the address of the new node). This way, any changes 
// made to the pointer within the function will affect the original pointer.
