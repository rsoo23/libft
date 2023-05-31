/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:55 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/31 10:53:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_del(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	wordnum(char const *s, char c)
{
	unsigned int	i;
	unsigned int	wordnum;

	i = 0;
	wordnum = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && is_del(s[i], c))
			i++;
		if (s[i] && !is_del(s[i], c))
			wordnum++;
		while (s[i] && !is_del(s[i], c))
			i++;
	}
	return (wordnum);
}

static int	wordlen(char const *s, unsigned int i, char c)
{
	unsigned int	j;
	unsigned int	wordlen;

	j = 0;
	wordlen = 0;
	if (!s)
		return (0);
	while (s[i + j] && !is_del(s[i + j], c))
	{
		wordlen++;
		j++;
	}
	return (wordlen);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (wordnum(s, c) + 1));
	if (!res || !s)
		return (0);
	while (s[i])
	{
		while (s[i] && is_del(s[i], c))
			i++;
		if (!s[i])
			break ;
		res[j] = malloc(sizeof(char) * (wordlen(s, i, c) + 1));
		k = 0;
		while (s[i] && !is_del(s[i], c))
			res[j][k++] = s[i++];
		res[j][k] = '\0';
		j++;
	}
	res[j] = 0;
	return (res);
}

// Note: the break is to exit when a null terminator is detected
// - if it is not there, then wordlen will give 0 and will store a 
// null terminator in res[j][k] resulting in an extra line in the 
// output

// int main()
// {
//     char s[] = "What is love baby don't hurt me       ";
//     char c = ' ';
//     int i = 0;
//     char **strings;

//     strings = ft_split(s, c);
//     while (strings[i])
//     {
//         printf("%s\n", strings[i]);
//         i++;
//     }
// }
