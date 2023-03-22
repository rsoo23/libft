/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:08:20 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/07 15:08:20 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char*  ptr1;
    unsigned char*  ptr2;
    size_t          i;

    ptr1 = (unsigned char*)s1;
    ptr2 = (unsigned char*)s2;
    while (i < n && ptr1[i] && ptr2[i] && ptr[1] == ptr[2])
        i++;
    return (ptr1[i] - ptr2[i]);
}

//Notes:
// strncmp compares strings
// memcmp compares memory blocks