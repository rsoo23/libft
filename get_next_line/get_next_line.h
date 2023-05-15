/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:14:31 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/30 15:14:31 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // read, close
# include <stdint.h> // size_t
// testing
# include <stdio.h>
# include <fcntl.h>  // open

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// get_next_line.c
char	*get_next_line(int fd);
char	*get_trimmed_line(char *untrimmed_line);
char	*get_endofline_buf(char *buf);
char	*read_buffer_assign(int fd, char *endofline_buf);
// get_next_line_utils.c
int		ft_find_newline_pos(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_free_ret_null(char *free_str);
char	*ft_strdup(const char *s);

#endif
