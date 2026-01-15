# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danimore <danimore@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 15:34:47 by danimore          #+#    #+#              #
#    Updated: 2025/01/06 15:14:35 by danimore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBNAME = libget_next_line.a

NAME = main

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

#create library
all: $(LIBNAME)

$(LIBNAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#create main
program: $(NAME)

$(NAME): $(LIBNAME) main.o
	$(CC) $(CFLAGS) -o $(NAME) main.o -L. -lget_next_line

main.o: $(NAME).c
	$(CC) $(CFLAGS) -c -Ilibget_next_line $(NAME).c

#clean and or rebuild
clean:
	rm -f $(OBJS)

fclean:
	rm -f $(LIBNAME) $(MAIN)
re: fclean all program