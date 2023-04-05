/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:26:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/30 19:13:45 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	size_t	*ptr;

	ptr = malloc(n_elem * size);
	if (!ptr || n_elem == 0 || size == 0)
		return (0);
	ft_bzero(ptr, n_elem * size);
	return (ptr);
}

// Why do we use n_elem * size in ft_bzero
