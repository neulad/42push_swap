/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:59:52 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/06/01 00:28:17 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*read_file(int fd, char *line, int *end_file)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_vars(line, buffer), NULL);
		*end_file = !bytes_read;
		buffer[bytes_read] = '\0';
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (free(buffer), NULL);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (free(buffer), line);
}

char	*copy_aftern(char *s)
{
	char	*res;
	char	*cs;
	int		i;

	cs = s;
	while (*s && *s != '\n')
		s++;
	if (*s)
		s++;
	res = malloc(sizeof(char) * (ft_strlen_gnl(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
		res[i++] = *s++;
	res[i] = '\0';
	free(cs);
	return (res);
}

char	*copy_tilln(char *s)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s && *s != '\n')
		res[i++] = *s++;
	if (*s == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*res;
	int			end_file;

	end_file = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (end_file && !line)
		return (NULL);
	line = read_file(fd, line, &end_file);
	if (!line)
		return (NULL);
	res = copy_tilln(line);
	line = copy_aftern(line);
	return (res);
}

/* #include <stdio.h>
int	main(void)
{
	char	*s;

	s = "";
	int fd = open("test.txt", O_RDONLY);
	while (s != NULL)
	{
		s = get_next_line(fd);
		printf("%s", s);
		if (s)
			free(s);
	}
	return (0);
} */
