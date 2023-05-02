/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:26:29 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/02 13:26:29 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_assign_form(const char **s, t_form *form)
{
	(*s)++;
	while (**s)
	{
		if (ft_valid_flag(**s, "-+0# "))
			ft_assign_flag(s, form);
		if (**s >= '1' && **s <= '9')
		{
			while (**s >= '0' && **s <= '9')
			{
				form->min_fw = (form->min_fw * 10) + (**s - 48);
				(*s)++;
			}
		}
		if (**s == '.')
		{
			form->prec_exist = 1;
			(*s)++;
			ft_assign_prec(**s, s, form);
		}
		if (ft_valid_assign_spec(**s, "cspdiuxX%", form) == 1)
			return (1);
		else
			break ;
	}
	return (ft_putstr("Format error: %[flag][.prec][mfw][spec]"));
}

int	ft_valid_flag(const char s, char *flag_str)
{
	while (*flag_str)
	{
		if (s == *flag_str)
			return (1);
		flag_str++;
	}
	return (0);
}

int	ft_assign_flag(const char **s, t_form *form)
{
	while (ft_valid_flag(**s, "-+0# "))
	{
		if (**s == '#')
			form->hash++;
		else if (**s == '0')
			form->zero++;
		else if (**s == '+')
			form->plus++;
		else if (**s == '-')
			form->minus++;
		else if (**s == ' ')
			form->space++;
		(*s)++;
	}
	return (1);
}

void	ft_assign_prec(const char nb, const char **s, t_form *form)
{
	if (nb >= '0' && nb <= '9')
	{
		while (**s >= '0' && **s <= '9')
		{
			form->prec = (form->prec * 10) + (**s - 48);
			(*s)++;
		}
	}
	else if (nb == '-')
	{
		form->prec = 0;
		(*s)++;
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
	else
		form->prec = 0;
	return ;
}

int	ft_valid_assign_spec(const char s, char *spec_str, t_form *form)
{
	while (*spec_str)
	{
		if (s == *spec_str)
		{
			form->spec = s;
			return (1);
		}
		spec_str++;
	}
	ft_putstr("Specifier error: valid = cspdiuxX%");
	return (0);
}
