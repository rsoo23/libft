/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:00:03 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/10 15:39:31 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr1;
	size_t			i;

	ptr1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] == (unsigned char)c)
			return (&ptr1[i]);
		i++;
	}
	return (0);
}
