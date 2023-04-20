/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:37:06 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/20 10:55:23 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start + 1;
	if (start >= ft_strlen(s))
		len = 0;
	if (len >= 0)
		substr = malloc(len * sizeof(char) + 1);
	else
		return (0);
	if (!substr)
		return (0);
	while (i < len && s[start])
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

// checks:
// !s ?
// start >= ft_strlen(s)

// #include <stdio.h>
// int main()
// {
//     char s[] = "pneumonoultramicroscopic";
//     printf("%s", ft_substr(s, 77, 5));
// }

// int main()
// {
// 	char *str;
// 	str = ft_strdup("1");
// 	printf("%s", ft_substr(str, 42, 42000000));
// }
