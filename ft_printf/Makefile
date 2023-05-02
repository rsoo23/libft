# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 12:08:43 by rsoo              #+#    #+#              #
#    Updated: 2023/03/27 12:08:43 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf
CFILES = ft_format_check ft_format_check_1 ft_print_hex ft_print_int ft_print_ptr ft_print_uint ft_printf ft_utils ft_utils_1 ft_utils_2

SRCS = $(addprefix $(srcs), $(addsuffix .c, $(CFILES)))
srcs = srcs/
OBJS_B = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)

bonus: $(NAME)

clean:
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = re all clean fclean bonus
