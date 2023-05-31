/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:09:07 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!ft_isascii(c))
		return (0);
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
//         printf("last occurrence of %c: %d\n", c, s, (int)(ptr - s));
// }
