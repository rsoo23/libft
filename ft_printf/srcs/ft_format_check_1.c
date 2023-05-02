/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check_bonus1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:19:02 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/04 16:19:02 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// checks for special rules, '-0', ' +'
int	ft_check_rule(t_form *form)
{
	if (form->hash == 1 && !ft_valid_assign_spec(form->spec, "xX", form))
		return (ft_putstr("Error: # only compatible with %xX"));
	if (form->zero == 1 && !ft_valid_assign_spec(form->spec, "diuxX", form))
		return (ft_putstr("Error: 0 only compatible with %diuxX"));
	if (form->plus == 1 && !ft_valid_assign_spec(form->spec, "di", form))
		return (ft_putstr("Error: + only compatible with %di"));
	if (form->space == 1 && !ft_valid_assign_spec(form->spec, "di", form))
		return (ft_putstr("Error: space only compatible with %di"));
	if (form->prec != 0 && !ft_valid_assign_spec(form->spec, "sdiuxX", form))
		return (ft_putstr("Error: prec only compatible with %sdiuxX"));
	if (form->minus == 1 && form->zero == 1)
		form->zero = 0;
	if (form->space == 1 && form->plus == 1)
		form->space = 0;
	if (form->prec_exist && form->zero != 0)
		form->zero = 0;
	return (1);
}
