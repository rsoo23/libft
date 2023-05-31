/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:29:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (ptr1 > ptr2)
	{
		while (n--)
			ptr1[n] = ptr2[n];
	}
	else if (ptr1 <= ptr2)
	{
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	return (dst);
}

// Notes:
// Designed to handle overlapping memory areas, avoiding data corruption

// Non overlapping:
//          "a shiny white sphere"
// start:      [---]
// replace:          [---]

// Overlapping:
//           123456789
//          "a shiny white sphere"
// start:      [---]              | ptr2
// replace:     [---]             | ptr1

// int main()
// {
//     char dst[] = "a shiny white sphere";
//     char *start = dst + 2;
//     char  *replace = dst + 18;

//     printf("Before: %s\n", dst);
//     memmove(replace, start, 5);
//     printf("After: %s\n", dst);
// }
