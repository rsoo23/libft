/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:09:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/05 23:09:07 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    while (i >= 0)
    {
        if (s[i] == c)
            return (&s[i]);
        i--;
    }
    return (0);
}

// #include<stdio.h>
// int main()
// {
//     char s[] = "pneumono";
//     int c = 'n';
//     char *ptr;

//     ptr = ft_strrchr(s, c);
//     if (ptr == NULL)
//         printf("The character %c is not found in %s\n", c, s);
//     else
//         printf("The last occurrence of the character %c found in %s in position %d\n", c, s, (int)(ptr - s));
// }
