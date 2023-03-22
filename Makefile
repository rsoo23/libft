# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 20:26:20 by rsoo              #+#    #+#              #
#    Updated: 2023/03/09 20:26:20 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a
CFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
CFILES_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = $(CFILES:.c=.o)
OBJS_B = $(CFILES_B:.c=.o)

all: $(LIB)

$(LIB): $(OBJS)
	@echo "Creating library..."
	@ar rcs $(LIB) ft_memset.o $(filter-out ft_memset.o,$(OBJS))

$(OBJS): $(CFILES) 
	@echo "Creating object files..."
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_B)
	@echo "Creating library with bonus..."
	@ar rcs $(LIB) $(OBJS) $(OBJS_B)

$(OBJS_B): $(CFILES_B) 
	@echo "Creating bonus object files..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing all object files..."
	@rm -f $(OBJS) $(OBJS_B)

fclean: clean
	@echo "Removing library..."
	@rm -f $(LIB)

re: fclean all

.PHONY = clean fclean re
