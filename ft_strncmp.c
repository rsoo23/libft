/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:22:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/30 10:15:08 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char s1[] = "testing";
//     char s2[] = "testina";

//     printf("%d\n", ft_strncmp(s1, s2, 7));
//     printf("%d\n", strncmp(s1, s2, 7));
// }
