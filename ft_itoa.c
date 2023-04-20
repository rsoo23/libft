/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:18 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/20 08:57:04 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	numlen;

	numlen = 0;
	if (n <= 0)
		numlen++;
	while (n != 0)
	{
		numlen++;
		n /= 10;
	}
	return (numlen);
}

static char	*ft_assign_num(char *res, long num, int l)
{
	res [l] = '\0';
	if (num == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		res[l-- - 1] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*res;
	int		l;

	num = n;
	l = ft_numlen(n);
	res = malloc(l * sizeof(char) + 1);
	if (!res)
		return (0);
	return (ft_assign_num(res, num, l));
}

// [- 2 3 4 5 \0]
//  0 1 2 3 4 5
// numlen = 4

// [2 3 4 5 \0]
//  0 1 2 3 4
// numlen = 3

// int main()
// {
//     printf("%s\n", ft_itoa(-2147483647));
// }
