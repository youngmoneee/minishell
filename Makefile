# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 21:45:14 by youngpar          #+#    #+#              #
#    Updated: 2022/04/22 22:05:41 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= MINISHELL
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

INC		= ./include

SHDIR	= ./shell
SHFILE	= main.c

SHSRC	= $(addprefix $(SHDIR)/, $(SHFILE))
SHOBJ	= $(SHSRC:.c=.o)

OBJS	= $(SHOBJ)

.c.o:
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CLFAGS) $(OBJS) -lpthread -lreadline -o $(NAME)

clean	:
	@rm -rf $(OBJS)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY	: all $(NAME) clean fclean re
