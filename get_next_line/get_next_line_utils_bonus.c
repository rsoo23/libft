/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:21:39 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/11 10:21:39 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_find_newline_pos(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char			*res;
// 	unsigned int	i;
// 	size_t			len1;
// 	size_t			len2;

// 	i = 0;
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	res = malloc(len1 + len2 + 1);
// 	if (!res)
// 		return (NULL);
// 	while (i++ < len1)
// 		res[i - 1] = s1[i - 1];
// 	i = 0;
// 	while (i++ < len2)
// 		res[i - 1 + len1] = s2[i - 1];
// 	res[i - 1 + len1] = '\0';
// 	free((char *)s1);
// 	return (res);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s && s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	char	*dest;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 		i++;
// 	dest = malloc(sizeof(char) * (i + 1));
// 	i = 0;
// 	while (s[i])
// 	{
// 		dest[i] = s[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_free_ret_null(char *free_str)
{
	free(free_str);
	free_str = NULL;
	return (NULL);
}
