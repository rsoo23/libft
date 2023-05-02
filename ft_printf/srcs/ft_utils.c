/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:23:43 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/31 14:23:43 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_form(t_form *form)
{
	form->hash = 0;
	form->zero = 0;
	form->plus = 0;
	form->minus = 0;
	form->space = 0;
	form->min_fw = 0;
	form->prec_exist = 0;
	form->prec = 0;
	form->form_len = 0;
	form->spec = '0';
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putchar_b(char c, t_form *form)
{
	form->form_len++;
	if (form->minus != 0)
		ft_putchar(c);
	while (form->form_len < form->min_fw)
	{
		ft_putchar(' ');
		form->form_len++;
	}
	if (form->minus == 0)
		ft_putchar(c);
}

void	ft_putstr_b(char *s, t_form *form)
{
	if (!s || (!s && !form->prec_exist))
		s = ft_strdup("(null)");
	if (form->prec_exist)
		while (form->form_len < form->prec && s[form->form_len])
			form->form_len++;
	else
		while (s[form->form_len])
			form->form_len++;
	if (form->minus != 0)
		ft_putstr_prec(s, form);
	while (form->form_len < form->min_fw)
	{
		ft_putchar(' ');
		form->form_len++;
	}
	if (form->minus == 0)
		ft_putstr_prec(s, form);
	if (ft_strncmp(s, "(null)", 10) == 0)
		free(s);
}

void	ft_putstr_prec(char *s, t_form *form)
{
	int	strcount;

	strcount = 0;
	if (form->prec_exist)
	{
		while (strcount < form->prec && s[strcount])
			ft_putchar(s[strcount++]);
	}
	else
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
	return ;
}
