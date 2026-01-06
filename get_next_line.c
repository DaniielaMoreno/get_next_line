/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimore <danimore@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:26:10 by danimore          #+#    #+#             */
/*   Updated: 2025/12/17 22:30:07 by danimore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	static char	*base_buffer;

	if (fd < 0)
		return (NULL);
	base_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!base_buffer)
	{
		return (NULL);
		free(base_buffer);
	}
	line = read(fd, base_buffer, 12);
}
