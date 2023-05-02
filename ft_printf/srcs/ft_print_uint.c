/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:29:29 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/05 23:29:29 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_uint_b(unsigned int nb, t_form *form)
{
	form->form_len += ft_len_uint(nb);
	if (form->prec_exist && nb != 0 && form->min_fw <= form->prec)
		form->zero = 1;
	if (!form->zero && form->prec_exist && !form->prec && !nb)
		form->form_len--;
	if (form->minus != 0)
		ft_put_uint_prec(nb, form);
	ft_put_uint_zero_space(nb, form);
	if (!form->minus)
		ft_put_uint_prec(nb, form);
}

int	ft_len_uint(unsigned int nb)
{
	int	i;

	i = 0;
	if (!nb)
		i++;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	ft_put_uint_prec(unsigned int nb, t_form *form)
{
	if (form->prec_exist && form->prec == 0 && nb == 0)
	{
		if (form->min_fw == 0)
			form->form_len = 0;
		return ;
	}
	while (form->form_len < form->prec)
	{
		ft_putchar('0');
		form->form_len++;
	}
	ft_put_uint(nb, form);
}

void	ft_put_uint(unsigned int nb, t_form *form)
{
	if (nb > 9)
		ft_put_uint(nb / 10, form);
	ft_putchar("0123456789"[nb % 10]);
	return ;
}

void	ft_put_uint_zero_space(unsigned int nb, t_form *form)
{
	if (form->min_fw && !form->minus && form->prec > form->form_len)
	{
		while (form->form_len < form->min_fw - (form->prec - ft_len_uint(nb)))
		{
			ft_putchar(' ');
			form->form_len++;
		}
		while (form->form_len < form->min_fw)
		{
			ft_putchar('0');
			form->form_len++;
		}
		return ;
	}
	ft_put_nbr_zero_space(nb, form);
}
