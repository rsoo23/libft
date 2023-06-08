/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:00:13 by rsoo              #+#    #+#             */
/*   Updated: 2023/05/11 10:00:13 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Find the fd limit using the shell command: ulimit -n
// or using: _SC_OPEN_MAX instead of 1024

// Tripouille test: change the timeout to 5,000,000 for big_line test

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=4 *.c && ./a.out

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*trimmed_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf[fd] = read_buffer_assign(fd, buf[fd]);
	trimmed_line = get_trimmed_line(buf[fd]);
	buf[fd] = get_endofline_buf(buf[fd]);
	return (trimmed_line);
}

char	*read_buffer_assign(int fd, char *buf)
{
	int		read_num;
	char	*buffer;

	read_num = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_find_newline_pos(buf) == -1)
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num <= 0)
			break ;
		buffer[read_num] = '\0';
		buf = ft_strjoin_gnl(buf, buffer);
	}
	free(buffer);
	if (read_num == -1)
		return (NULL);
	return (buf);
}

char	*get_trimmed_line(char *untrimmed_line)
{
	int		len;
	int		nl_pos;
	char	*trimmed_line;

	len = -1;
	if (!ft_strlen_gnl(untrimmed_line))
		return (NULL);
	nl_pos = ft_find_newline_pos(untrimmed_line);
	if (nl_pos == -1)
	{
		trimmed_line = ft_strdup_gnl(untrimmed_line);
		return (trimmed_line);
	}
	trimmed_line = malloc((nl_pos + 2) * sizeof(char));
	if (!trimmed_line)
		return (ft_free_ret_null(trimmed_line));
	while (len++ <= nl_pos)
		trimmed_line[len] = untrimmed_line[len];
	trimmed_line[len - 1] = '\0';
	return (trimmed_line);
}

char	*get_endofline_buf(char *buf)
{
	size_t	buf_count;
	int		nl_pos;
	char	*trimmed_buf;

	buf_count = 0;
	if (!buf)
		return (ft_free_ret_null(buf));
	nl_pos = ft_find_newline_pos(buf);
	if (nl_pos == -1)
		return (ft_free_ret_null(buf));
	trimmed_buf = malloc((ft_strlen_gnl(buf) - nl_pos) * sizeof(char));
	if (!trimmed_buf)
		return (ft_free_ret_null(trimmed_buf));
	nl_pos++;
	while (buf[nl_pos])
		trimmed_buf[buf_count++] = buf[nl_pos++];
	trimmed_buf[buf_count] = '\0';
	free(buf);
	return (trimmed_buf);
}

// int main()
// {
//     int fd1 = open("file.txt", O_RDONLY);
//     int fd2 = open("file1.txt", O_RDONLY);
//     int fd3 = open("file2.txt", O_RDONLY);
//     int i = 0;

//     while (i < 3)
//     {
//        printf("%d:%s", i, get_next_line(fd1));
//        printf("%d:%s", i, get_next_line(fd2));
//        printf("%d:%s", i, get_next_line(fd3));
//        i++;
//     }
// }
