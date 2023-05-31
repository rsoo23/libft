/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:47:41 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (0);
	new_elem -> content = content;
	new_elem -> next = NULL;
	return (new_elem);
}

// int main()
// {
//     printf("%p\n", ft_lstnew((void*)3)-> content);
//     printf("%p\n", ft_lstnew((void*)2)-> content);
//     printf("%p\n", ft_lstnew((void*)3)-> next);
//     printf("%p\n", ft_lstnew((void*)2)-> next);
// }
