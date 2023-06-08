/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:14:30 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/01 21:14:30 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
// # include <stdio.h>

typedef struct s_form
{
	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		space;
	int		min_fw;
	int		prec_exist;
	int		prec;
	int		form_len;
	char	spec;
}				t_form;

int		ft_printf(const char *s, ...);
int		ft_parse(va_list ap, const char **s);
// ft_format_check.c
int		ft_valid_flag(const char s, char *flag_str);
int		ft_valid_assign_spec(const char s, char *spec_str, t_form *form);
int		ft_assign_flag(const char **s, t_form *form);
int		ft_assign_form(const char **s, t_form *form);
void	ft_assign_prec(const char nb, const char **s, t_form *form);
// ft_format_check_1.c
int		ft_check_rule(t_form *form);
// ft_utils.c
void	ft_init_form(t_form *form);
void	ft_putchar_b(char c, t_form *form);
void	ft_putstr_b(char *s, t_form *form);
void	ft_putstr_prec(char *s, t_form *form);
// ft_utils_1.c
int		ft_valid_input(const char c, char *str);
void	ft_put_zero_space(t_form *form);
int		ft_putstr(char *str);
int		ft_putchar(char c);
char	*ft_strdup(const char *s);
// ft_utils_2.c
void	ft_put_nbr_zero_space(int nb, t_form *form);
void	ft_put_hex_zero_space(unsigned int nb, t_form *form);
// ft_print_hex.c
int		ft_hex_len(uintptr_t nb, t_form *form);
void	ft_puthex_hash(t_form *form);
void	ft_puthex_flag(unsigned int nb, t_form *form);
void	ft_puthex_b(unsigned int nb, t_form *form);
void	ft_puthex(unsigned int nb, t_form *form);
// ft_print_ptr.c
void	ft_put_ptr_b(uintptr_t nb, t_form *form);
void	ft_puthex_ptr(uintptr_t nb);
void	ft_put_ptr(uintptr_t nb);
// ft_print_int.c
void	ft_put_int(int nb, t_form *form);
int		ft_len_int(int nb);
void	ft_put_int_b(int nb, t_form *form);
void	ft_put_int_space_plus(int nb, t_form *form);
void	ft_put_int_zero_space(int *nb, t_form *form);
// ft_print_uint.c
void	ft_put_uint_b(unsigned int nb, t_form *form);
int		ft_len_uint(unsigned int nb);
void	ft_put_uint(unsigned int nb, t_form *form);
void	ft_put_uint_prec(unsigned int nb, t_form *form);
void	ft_put_uint_zero_space(unsigned int nb, t_form *form);

#endif