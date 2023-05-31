/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:57:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 11:05:41 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Note: any function is used, compile all the files together at once

// ver2:
char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*res;
	unsigned int	i;
	size_t			len1;
	size_t			len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	while (i++ < len1)
		res[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < len2)
		res[i - 1 + len1] = s2[i - 1];
	res[i - 1 + len1] = '\0';
	free((char *)s1);
	return (res);
}

// ver1:
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char			*res;
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (0);
// 	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!res)
// 		return (0);
// 	while (s1[i])
// 		res[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		res[j++] = s2[i++];
// 	res[j] = '\0';
// 	return (res);
// }

// int main()
// {
//     char    s1[] = "mini";
//     char    s2[] = " cooper";
//     printf("%s\n", ft_strjoin(s1, s2));
// }
