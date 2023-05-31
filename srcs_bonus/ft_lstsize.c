/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 23:34:29 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int main()
// {
//     t_list *head = NULL;
//     t_list *one = NULL;
//     t_list *two = NULL;

//     head = ft_lstnew((void*)20);
//     one = ft_lstnew((void*)21);
//     two = ft_lstnew((void*)22);

//     ft_lstadd_front(&head, one);
//     ft_lstadd_front(&head, two);

//     printf("%d\n", ft_lstsize(head));
// }
