/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimore <danimore@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:23:50 by danimore          #+#    #+#             */
/*   Updated: 2025/01/15 19:40:16 by danimore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *raw_line, int *bytes_read)
{
	char	*buffer;
	char	*temp;

	if (!raw_line)
		raw_line = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(raw_line), NULL);
	*bytes_read = 1;
	while (!ft_strchr(raw_line, '\n') && *bytes_read != 0)
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read < 0)
			return (free(buffer), free(raw_line), NULL);
		buffer[*bytes_read] = '\0';
		temp = raw_line;
		raw_line = ft_strjoin(temp, buffer);
		if (!raw_line)
			return (free(buffer), free(temp), NULL);
		free(temp);
	}
	free(buffer);
	return (raw_line);
}

char	*ft_clean_line(char *raw_line)
{
	int		i;
	char	*clean_line;

	if (!raw_line || !raw_line[0])
		return (NULL);
	i = 0;
	while (raw_line[i] && raw_line[i] != '\n')
		i++;
	clean_line = ft_calloc(i + 2, sizeof(char));
	if (!clean_line)
		return (NULL);
	i = 0;
	while (raw_line[i] && raw_line[i] != '\n')
	{
		clean_line[i] = raw_line[i];
		i++;
	}
	if (raw_line[i] == '\n')
	{
		clean_line[i] = raw_line[i];
		i++;
	}
	clean_line[i] = '\0';
	return (clean_line);
}

char	*ft_rest_line(char *raw_line)
{
	size_t	i;
	size_t	len;
	char	*rest_line;

	i = 0;
	while (raw_line[i] != '\0' && raw_line[i] != '\n')
		i++;
	if (!raw_line[i])
		return (free(raw_line), NULL);
	i++;
	len = ft_strlen(raw_line) - i;
	rest_line = ft_calloc((len + 1), sizeof(char));
	if (!rest_line)
		return (free(raw_line), NULL);
	len = 0;
	while (raw_line[i])
		rest_line[len++] = raw_line[i++];
	free (raw_line);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*next_line;
	int			bytes_read;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = ft_read(fd, line[fd], &bytes_read);
	if (!line[fd])
		return (NULL);
	next_line = ft_clean_line(line[fd]);
	line[fd] = ft_rest_line(line[fd]);
	if (!next_line)
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	return (next_line);
}
