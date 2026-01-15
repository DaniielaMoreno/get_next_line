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
	/*char	nr;
	char	*base;
	char	*end;
	char	*file;

	base = "files/";
	end = ".txt";

	nr = '1';
	while (nr <= '7')
	{
		file = ft_strjoin(base, &nr);
		file = ft_strjoin(file, end);
		nr++;
		printf("%s\n", file);
	}
	return (0);*/

	int	fd;
	int	i;
	int	check;
	char	*line;
//--------------- TEST 1
	printf("\nTest 1: \033[36mEMPTY FILE\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/1_empty.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free(line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033Test 1:[31m[FAIL]\033[0m\n");
	printf("\033[32mTest 1:[OK]\033[0m\n");
//--------------- TEST 2
	printf("\nTest 2: \033[36mJUST ONE NEW LINE\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/1_empty.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free (line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033Test 2:[31m[FAIL]\033[0m\n");
	printf("\033[32mTest 2:[OK]\033[0m\n");
//--------------- TEST 3
	printf("\nTest 3: \033[36mJUST NEW LINES\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/3_5xnl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free (line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033[31mTest 3:[FAIL]\033[0m\n");
	printf("\033[32mTest 3:[OK]\033[0m\n");
//--------------- TEST 4
	printf("\nTest 4: \033[36mPOEM WITH NEW LINES AND FINAL NL\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/4_poem_endnl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free (line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033[31mTest 4:[FAIL]\033[0m\n");
	printf("\033[32mTest 4:[OK]\033[0m\n");
//--------------- TEST 5
	printf("\nTest 5: \033[36mPOEM WITH NEW LINES AND NO FINAL NL\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/5_poem_no_endnl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free (line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033[31mTest 5:[FAIL]\033[0m\n");
	printf("\033[32mTest 5:[OK]\033[0m\n");
//--------------- TEST 6
	printf("\nTest 6: \033[36mBIG LINE WITH FINAL NL\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/6_bigline_endnl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free (line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033[31mTest 6:[FAIL]\033[0m\n");
	printf("\033[32mTest 6:[OK]\033[0m\n");
//--------------- TEST 7
	printf("\nTest 7: \033[36mBIG LINE WITHOUT FINAL NL\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/7_bigline_no_nl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free (line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033[31mTest 7:[FAIL]\033[0m\n");
	printf("\033[32mTest 7:[OK]\033[0m\n");
//--------------- TEST 8
	printf("\nTest 8: \033[36mBIG TEXT WITH NL AND NO FINAL NL\033[0m\n");

	i = 0;
	check = 0;
	fd = open("files/8_bigline_nl_no_endnl.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("File not found");
		return (0);
		
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
			check = 1;
		i++;
		printf("[%d]:%s\n", i, line);
		line = NULL;
	}
	free (line);
	close (fd);
	if (check == 1 && i == 0)
		printf("\033[31mTest 8:[FAIL]\033[0m\n");
	printf("\033[32mTest 8:[OK]\033[0m\n");

	return (0);
}