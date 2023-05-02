/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:15:57 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/30 20:15:57 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_ptr_b(uintptr_t nb, t_form *form)
{
	form->form_len += ft_hex_len(nb, form);
	if (form->minus)
		ft_put_ptr(nb);
	while (form->form_len < form->min_fw)
	{
		ft_putchar(' ');
		form->form_len++;
	}
	if (!form->minus)
		ft_put_ptr(nb);
}

void	ft_put_ptr(uintptr_t nb)
{
	ft_putstr("0x");
	ft_puthex_ptr(nb);
}

void	ft_puthex_ptr(uintptr_t nb)
{
	if (nb >= 16)
		ft_puthex_ptr(nb / 16);
	ft_putchar("0123456789abcdef"[nb % 16]);
}
