# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 21:45:14 by youngpar          #+#    #+#              #
#    Updated: 2022/05/06 20:51:42 by dongkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	= libbuiltin.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

INCDIR	= -I ./include

DIR		= ./srcs
FILE	= echo.c \
			#stack.c

SRCS	= $(addprefix $(DIR)/, $(FILE))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

clean	:
	@rm -rf $(OBJS)

fclean	: clean
	@rm -rf $(TARGET)

re		: fclean all

.PHONY	: all clean fclean re
