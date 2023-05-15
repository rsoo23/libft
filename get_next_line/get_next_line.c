/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:13:14 by rsoo              #+#    #+#             */
/*   Updated: 2023/04/30 15:13:14 by rsoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Tripouille test: change the timeout to 4,500,000 for big_line test

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=4 *.c && ./a.out

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*endofline_buf;
	char		*trimmed_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	endofline_buf = read_buffer_assign(fd, endofline_buf);
	trimmed_line = get_trimmed_line(endofline_buf);
	endofline_buf = get_endofline_buf(endofline_buf);
	return (trimmed_line);
}

char	*read_buffer_assign(int fd, char *endofline_buf)
{
	int		read_num;
	char	*buffer;

	read_num = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ft_find_newline_pos(endofline_buf) == -1)
	{
		read_num = read(fd, buffer, BUFFER_SIZE);
		if (read_num <= 0)
			break ;
		buffer[read_num] = '\0';
		endofline_buf = ft_strjoin(endofline_buf, buffer);
	}
	free(buffer);
	if (read_num == -1)
		return (NULL);
	return (endofline_buf);
}

char	*get_trimmed_line(char *untrimmed_line)
{
	int		len;
	int		nl_pos;
	char	*trimmed_line;

	len = -1;
	if (!ft_strlen(untrimmed_line))
		return (NULL);
	nl_pos = ft_find_newline_pos(untrimmed_line);
	if (nl_pos == -1)
	{
		trimmed_line = ft_strdup(untrimmed_line);
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
	trimmed_buf = malloc((ft_strlen(buf) - nl_pos) * sizeof(char));
	if (!trimmed_buf)
		return (ft_free_ret_null(trimmed_buf));
	nl_pos++;
	while (buf[nl_pos])
		trimmed_buf[buf_count++] = buf[nl_pos++];
	trimmed_buf[buf_count] = '\0';
	free(buf);
	return (trimmed_buf);
}

// int	main()
// {
// 	int	fd = open("file.txt", O_RDONLY);

// 	if (fd == -1)
// 		return(1);
// 	printf("1: %s", get_next_line(fd));
// 	printf("2: %s", get_next_line(fd));
// 	printf("3: %s", get_next_line(fd));
// 	printf("4: %s", get_next_line(fd));
// 	close(fd);
// }
