/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:26:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/17 14:31:39 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	size_t	*ptr;

	if (n_elem == SIZE_MAX || size == SIZE_MAX)
		return (0);
	ptr = malloc(n_elem * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n_elem * size);
	return (ptr);
}

// Why do we use n_elem * size in ft_bzero
