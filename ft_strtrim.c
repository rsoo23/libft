/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:17:03 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/08 16:17:03 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_wspace(char c, char const *set)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    unsigned int    i;
    unsigned int    len;
    char            *res;

    i = 0;
    len = 0;
    while (s1[i] && is_wspace(s1[i], set))
        i++;
    while (s1[i + len] && !is_wspace(s1[i], set))
        len++;

    res = malloc(len * sizeof(char) + 1);
    if (!res)
        return (0);

    len = 0;
    while (s1[i] && !is_wspace(s1[i], set))
        res[len++] = s1[i++];
    res[len] = '\0';

    return (res);
}

// int main()
// {
//     char s1[] = "racecar";
//     char *set = "r";

//     printf("%s\n", ft_strtrim(s1, set));
// }
