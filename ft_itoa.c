/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:47:18 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/30 09:37:37 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	numlen;

	numlen = 0;
	if (n < 0)
		numlen++;
	while (n != 0)
	{
		numlen++;
		n /= 10;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		l;

	l = numlen(n);
	res = malloc(l * sizeof(char) + 1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	if (!res)
		return (0);
	res [l] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res[l-- - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
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
