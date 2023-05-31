/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:42:11 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(char *s, int c)
{
	if (!ft_isascii(c))
		return (0);
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (&(*s));
}

// int main()
// {
//     char s[] = "pneumonoultramicroscopic";
//     int c = 'm';
//     char *ptr;

//     ptr = ft_strchr(s, c);
//     if (ptr == NULL)
//         printf("The character %c is not found in %s\n", c, s);
//     else
//         printf("%c is found in %s in position %d\n", c, s, (int)(ptr - s));
// }
