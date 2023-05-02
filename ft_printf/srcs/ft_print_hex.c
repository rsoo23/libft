/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:25:19 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/03 14:25:19 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_puthex_b(unsigned int nb, t_form *form)
{
	if (form->prec_exist && nb != 0 && form->min_fw <= form->prec)
		form->zero = 1;
	form->form_len += ft_hex_len(nb, form);
	if (form->minus != 0)
		ft_puthex_flag(nb, form);
	else if (!form->minus && form->zero && form->hash)
	{
		ft_puthex_hash(form);
		form->zero = 2;
	}
	if (form->zero && form->prec_exist && !form->prec && !nb)
		form->form_len--;
	if (!form->zero && form->prec_exist && !form->prec && !nb && form->min_fw)
		form->form_len--;
	ft_put_hex_zero_space(nb, form);
	if (!form->minus)
		ft_puthex_flag(nb, form);
}

void	ft_puthex_hash(t_form *form)
{
	if (form->hash && form->spec == 'x')
		ft_putstr("0x");
	else if (form->hash && form->spec == 'X')
		ft_putstr("0X");
}

void	ft_puthex_flag(unsigned int nb, t_form *form)
{
	if (form->prec_exist && !form->prec && !nb)
	{
		if (form->min_fw == 0)
			form->form_len = 0;
		return ;
	}
	if (form->zero != 2 && nb != 0)
		ft_puthex_hash(form);
	if (form->prec_exist && form->form_len < form->prec)
	{
		while (form->form_len < form->prec)
		{
			ft_putchar('0');
			form->form_len++;
		}
	}
	ft_puthex(nb, form);
	return ;
}

void	ft_puthex(unsigned int nb, t_form *form)
{
	if (nb >= 16)
		ft_puthex(nb / 16, form);
	if (form->spec == 'x')
		ft_putchar("0123456789abcdef"[nb % 16]);
	else if (form->spec == 'X')
		ft_putchar("0123456789ABCDEF"[nb % 16]);
	return ;
}

int	ft_hex_len(uintptr_t nb, t_form *form)
{
	int	i;

	i = 0;
	if ((form->hash && nb != 0) || form->spec == 'p')
		i += 2;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		i++;
		nb /= 16;
	}
	return (i);
}
