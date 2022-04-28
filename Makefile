# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 21:45:14 by youngpar          #+#    #+#              #
#    Updated: 2022/04/26 18:54:09 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LDLIBS	= -lpthread \
		  -lreadline \
		  -lbuiltin

RLDIR	= /opt/homebrew/opt/readline
RLINC	= $(RLDIR)/include

LIBDIR	= -L $(RLDIR)/lib \
		  -L./libs

INCDIR	= -I ./inc \
		  -I $(RLINC)

SHDIR	= ./srcs
SHFILE	= main.c \
		  ft_utils.c \
		  combkey.c \
		  parsing.c \
		  minishell.c

SRCS	= $(addprefix $(SHDIR)/, $(SHFILE))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(TARGET)

$(TARGET): $(OBJS) library
	$(CC) $(CLFAGS) $(OBJS) $(LIBDIR) $(LDLIBS) -o $(TARGET)

library	:
	@make -C libs

clean	:
	@rm -rf $(OBJS)
	@make -C libs clean

fclean	: clean
	@rm -rf $(TARGET)
	@make -C libs fclean

re		: fclean all

.PHONY	: all clean fclean re
