/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:22:21 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/13 09:39:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// these two are casted to unsigned int to avoid possibility of
// int overflow

// #include<stdio.h>
// #include<string.h>
// int main()
// {                
//     char s1[] = "abcdef";
//     char s2[] = "abcdefghijklmnop";

//     printf("%d\n", ft_strncmp(s1, s2, 0));
//     printf("%d\n", strncmp(s1, s2, 0));
// }
