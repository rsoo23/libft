/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:02:37 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/11 10:02:37 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // read, close
# include <stdint.h> // size_t
// testing
// # include <stdio.h>
// # include <fcntl.h>  // open
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// get_next_line_bonus.c
char	*get_next_line(int fd);
char	*get_trimmed_line(char *untrimmed_line);
char	*get_endofline_buf(char *buf);
char	*read_buffer_assign(int fd, char *endofline_buf);
// get_next_line_utils_bonus.c
int		ft_find_newline_pos(char *str);
char	*ft_free_ret_null(char *free_str);

#endif