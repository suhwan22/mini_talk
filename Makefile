# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 02:33:10 by suhkim            #+#    #+#              #
#    Updated: 2022/09/30 02:41:09 by suhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server
NAME2 = client
SRCS1 = server.c
SRCS2 = client.c
OBJS = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all: $(NAME) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $<

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS) $(OBJS2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
