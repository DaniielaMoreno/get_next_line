/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimore <danimore@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:14:13 by danimore          #+#    #+#             */
/*   Updated: 2025/01/14 15:16:23 by danimore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *raw_line, int *bytes_read);
char	*ft_clean_line(char *raw_line);
char	*ft_rest_line(char *raw_line);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif