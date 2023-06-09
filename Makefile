# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 20:26:20 by rsoo              #+#    #+#              #
#    Updated: 2023/05/31 10:59:57 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
AR = ar rcs
RM = rm -rf
SRCS_DIR = srcs/
SRCS_B_DIR = srcs_bonus/
FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
FILES_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
CFILES = $(addprefix $(SRCS_DIR), $(FILES))
CFILES_B = $(addprefix $(SRCS_B_DIR), $(FILES_B))

OBJS = $(CFILES:.c=.o)
OBJS_B = $(CFILES_B:.c=.o)

GNLDIR = get_next_line/
GNL_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c
GNL_CFILES = $(addprefix $(GNLDIR), $(GNL_FILES))
GNL_OBJS = $(GNL_CFILES:.c=.o)

FT_PRINTF_DIR = ft_printf/srcs/
FT_PRINTF_SRCS = ft_format_check ft_format_check_1 ft_print_hex ft_print_int ft_print_ptr ft_print_uint ft_printf ft_utils ft_utils_1 ft_utils_2
FT_PRINTF_CFILES = $(addprefix $(FT_PRINTF_DIR), $(addsuffix .c, $(FT_PRINTF_SRCS)))
FT_PRINTF_OBJS = $(FT_PRINTF_CFILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	$(AR) $(NAME) $(OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

bonus: $(OBJS) $(OBJS_B) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	$(AR) $(NAME) $(OBJS) $(OBJS_B) $(GNL_OBJS) $(FT_PRINTF_OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_B) $(GNL_OBJS) $(FT_PRINTF_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re all
