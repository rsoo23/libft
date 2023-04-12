/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:37:06 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/12 10:07:08 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = malloc(len * sizeof(char) + 1);
	i = 0;
	if (!substr || !s)
		return (0);
	if (start >= ft_strlen(s))
		return (substr);
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

// int main()
// {
//     char s[] = "pneumonoultramicroscopic";
//     printf("%s", ft_substr(s, 8, 5));
// }
