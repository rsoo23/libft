/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:08:39 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/24 22:08:39 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_nbr_zero_space(int nb, t_form *form)
{
	while (form->form_len < form->min_fw)
	{
		if (form->prec_exist && !form->prec && !nb)
			ft_putchar(' ');
		else if (form->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		form->form_len++;
	}
}

void	ft_put_hex_zero_space(unsigned int nb, t_form *form)
{
	int	space_num;

	space_num = form->min_fw - (form->prec - ft_hex_len(nb, form));
	if (form->min_fw && !form->minus && form->prec > form->form_len)
	{
		while (form->form_len < space_num)
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
