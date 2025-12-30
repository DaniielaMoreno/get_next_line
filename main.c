/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c.                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimore <danimore@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 22:26:10 by danimore          #+#    #+#             */
/*   Updated: 2025/12/17 22:30:07 by danimore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;
	char	*line;

	i = 0;
	fd = open("poem.txt", O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
		printf("File not found");
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		i++;
		prinft("%s", line);
	}
	return (0);
}