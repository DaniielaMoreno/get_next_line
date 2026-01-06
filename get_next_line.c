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
	static char	*baby_buffer;

	if (fd < 0)
		return (NULL);
	baby_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!baby_buffer)
	{
		return (NULL);
		free(baby_buffer);
	}
}
