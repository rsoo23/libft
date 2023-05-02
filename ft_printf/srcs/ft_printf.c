/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 21:01:26 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/02 21:01:26 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (*s == '\0')
		return (ft_putstr("Error: empty string"));
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			len += ft_putchar(*s);
		else
			len += ft_parse(ap, &s);
		s++;
	}
	va_end(ap);
	return (len);
}

int	ft_parse(va_list ap, const char **s)
{
	t_form	*form;

	form = malloc(sizeof(t_form));
	ft_init_form(form);
	if (ft_assign_form(s, form) == 1 && ft_check_rule(form) == 1)
	{
		if (form->spec == 'c')
			ft_putchar_b(va_arg(ap, int), form);
		else if (form->spec == 'p')
			ft_put_ptr_b(va_arg(ap, uintptr_t), form);
		else if (form->spec == 'x' || form->spec == 'X')
			ft_puthex_b(va_arg(ap, unsigned int), form);
		else if (form->spec == '%')
			form->form_len += ft_putchar('%');
		else if (form->spec == 'd' || form->spec == 'i')
			ft_put_int_b(va_arg(ap, int), form);
		else if (form->spec == 'u')
			ft_put_uint_b(va_arg(ap, unsigned int), form);
		else if (form->spec == 's')
			ft_putstr_b(va_arg(ap, char *), form);
	}
	free(form);
	return (form->form_len);
}

// int main(void)
// {
// 	printf("%d", ft_printf("%02.0x", 0));
// }

// int	main(void)
// {
//     %c
//     printf("%d", ft_printf("%5c now you see", '\0'));
//     printf("%d\n", printf("test: %10c", 'z'));

//     %p
//     char    c = 'b';
//     printf("%d\n", ft_printf("%-25p", &c));
//     printf("%d\n", printf("%-25p", &c)); 

//     %x and %X
//     printf("%d\n", ft_printf("%x", -123));
//     printf("%d\n", printf("%x", -123));
//     printf("%d\n", ft_printf("%#-15X", -2234));
//     printf("%d\n", printf("%#-15X", -2234));

//     %%
//     printf("%d\n", ft_printf("%%"));
//     printf("%d\n", printf("%%"));

//     %d or %i flags: mfw 0 - + ' '
//     int num = -43;
//     printf("%d\n", ft_printf("% -d", num));
//     printf("%d\n", printf("% -d", num));

//     %u flags: mfw 0 - 
//     unsigned int    i = 12345;
//     printf("%d\n", ft_printf("%-4u", i));
//     printf("%d\n", printf("%-4u", i));

// 	   %s flags: - prec mfw
		// printf("%d\n", ft_printf("%10s", ""));
		// printf("%d\n", printf("%10s", ""));

//     printf("%4", 'a');
//     ft_printf("char: %#c", 'a');
// }
