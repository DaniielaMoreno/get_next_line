/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimore <danimore@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 23:04:56 by danimore          #+#    #+#             */
/*   Updated: 2025/12/17 23:05:23 by danimore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);