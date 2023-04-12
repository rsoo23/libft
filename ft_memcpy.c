/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:40 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/10 14:41:03 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dst && !src)
		return (0);
	i = 0;
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

// Notes:
// Doesn't prevent overlapping memory
// a = {1, 2, 3}
// b = {4, 5, 6}
// memcpy(b, a, 2 * sizeof(int)) = {1, 2, 6}
// memcpy(b + 2, a, 1 * sizeof(int)) = {4, 5, 1} 