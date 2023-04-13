/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:17:03 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/13 09:00:30 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_wspace(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*res;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (s1[i] && is_wspace(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (s1[j] && is_wspace(s1[j], set))
		j--;
	res = malloc((j - i + 1) * sizeof(char) + 1);
	if (!res)
		return (0);
	while (i <= j)
		res[k++] = s1[i++];
	res[k] = '\0';
	return (res);
}

// int main()
// {
//     char s1[] = "  \t \t \n   \n\n\n\t";
//     char *set = " \n\t";

//     printf("%s\n", ft_strtrim(s1, set));
// }
