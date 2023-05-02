/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:58 by rsoo              #+#    #+#             */
/*   Updated: 2023/03/27 15:29:58 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_int_b(int nb, t_form *form)
{
	form->form_len += ft_len_int(nb);
	if ((nb >= 0 && form->plus) || (nb >= 0 && form->space))
		form->form_len++;
	if (!form->minus && nb != 0 && form->min_fw && form->min_fw <= form->prec)
		form->zero = 1;
	if (!form->zero && form->prec_exist && form->prec == 0 && nb == 0)
		form->form_len--;
	if (form->minus != 0)
		ft_put_int_space_plus(nb, form);
	else if (form->plus && nb > 0)
	{
		ft_putchar('+');
		form->plus = 2;
	}
	if (nb < 0 && form->zero)
	{
		ft_putchar('-');
		if (nb != -2147483648)
			nb = -nb;
		form->prec++;
	}
	ft_put_int_zero_space(&nb, form);
	if (form->minus == 0)
		ft_put_int_space_plus(nb, form);
}

void	ft_put_int_space_plus(int nb, t_form *form)
{
	if (form->prec_exist && form->prec == 0 && nb == 0)
	{
		if (form->min_fw == 0)
			form->form_len = 0;
		return ;
	}
	if (nb >= 0 && form->space)
		ft_putchar(' ');
	else if (nb >= 0 && form-> plus == 1)
		ft_putchar('+');
	if (form->prec_exist && form->form_len <= form->prec)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
			form->prec++;
		}
		while (form->form_len < form->prec)
		{
			ft_putchar('0');
			form->form_len++;
		}
	}
	ft_put_int(nb, form);
}

void	ft_put_int_zero_space(int *nb, t_form *form)
{
	if (form->min_fw && !form->minus && form->prec > form->form_len)
	{
		if (*nb < 0)
			form->prec++;
		while (form->form_len < form->min_fw - (form->prec - ft_len_int(*nb)))
		{
			ft_putchar(' ');
			form->form_len++;
		}
		if (*nb < 0)
		{
			ft_putchar('-');
			*nb = -(*nb);
		}
		while (form->form_len < form->min_fw)
		{
			ft_putchar('0');
			form->form_len++;
		}
		return ;
	}
	ft_put_nbr_zero_space(*nb, form);
}

int	ft_len_int(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (11);
	if (nb <= 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	ft_put_int(int nb, t_form *form)
{
	if (nb == -2147483648)
	{
		if (form->prec > 10 || form->zero)
		{
			write(1, "2147483648", 10);
			return ;
		}
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_put_int(-nb, form);
	}
	else if (nb > 9)
	{
		ft_put_int(nb / 10, form);
		ft_put_int(nb % 10, form);
	}
	else
		ft_putchar(nb + 48);
}
