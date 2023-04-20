/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:31:53 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/20 10:10:36 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = 0;
	srclen = 0;
	while (dst[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	if (dstlen >= size)
		return (srclen + size);
	while (src[i] && i < size - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// Note:
// - size of dest must be >= dstlen+n+1
// - size_t size = size of buffer
// - assume that the buffer size >= dstlen + 1

// ** if the buffer size is insufficient it will return
//    srclen + size (portion of dst that can fit into size)
// ** this result tells the user that the result is truncated
// 

// o n e _ _ _ _

// #include <bsd/string.h>

// #include <stdio.h>
// int main()
// {
//     char dst[] = "B";
//     char src[] = "AAAAAAAAA";

//     printf("%ld\n", ft_strlcat(dst, src, 1));
// }

//Note:
// when compiling strlcat add -lbsd flag