/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahin <ashahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:42:14 by ashahin           #+#    #+#             */
/*   Updated: 2022/11/01 03:26:27 by ashahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returning to index of the character given as Parameter */
size_t	ft_find_char(const char *s, int c)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (s[i] == (unsigned char) c)
			return (i);
		i++;
	}
	return (i);
}

/* and substracting the returned line from the buffer */
char	*reset_func(char **buffer)
{
	char	*reset_buf;
	int		i;

	if (!*buffer)
		return (*buffer);
	i = ft_find_char(*buffer, '\n');
	i++;
	if ((size_t) i >= ft_strlen(*buffer))
	{
		free(*buffer);
		*buffer = NULL;
		return (*buffer);
	}
	else
	{
		reset_buf = myft_substr(*buffer, i, ft_strlen(*buffer));
		if (reset_buf[0] == '\0')
		{
			free(reset_buf);
			reset_buf = NULL;
		}
		free(*buffer);
		return (reset_buf);
	}
}

/* extracting line from buffer to a line string and return it */
char	*return_line(char **buffer)
{
	char	*ret_line;
	size_t	i;

	if (!*buffer)
		return (*buffer);
	i = 0;
	i = ft_find_char(*buffer, '\n');
	i++;
	ret_line = myft_substr(*buffer, 0, i);
	return (ret_line);
}

/* reading 42Bytes one time (coould be done serval times until '\n' is
 added to read_str then adding them  to the buffer and return teh buffer */
char	*read_file(int fd, char **buffer)
{
	int		read_ret;
	char	*read_str;
	char	*temp;

	read_str = malloc(BUFFER_SIZE + 1);
	if (!read_str)
		return (NULL);
	read_ret = 1;
	while (read_ret != 0 && !ft_strrchr(*buffer, '\n'))
	{
		read_ret = read(fd, read_str, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(read_str);
			return (NULL);
		}
		read_str[read_ret] = '\0';
		temp = *buffer;
		*buffer = myft_strjoin(*buffer, read_str);
		free(temp);
	}
	free(read_str);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_LENGTH];
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_file(fd, &buffer[fd]);
	ret_line = return_line(&buffer[fd]);
	buffer[fd] = reset_func(&buffer[fd]);
	return (ret_line);
}
