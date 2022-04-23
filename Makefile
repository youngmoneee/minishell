# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 21:45:14 by youngpar          #+#    #+#              #
#    Updated: 2022/04/23 20:35:35 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minish
CC		= gcc
LIBS	= -lpthread \
		  -lreadline
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
	$(CC) $(CLFAGS) $(OBJS) $(LIBS) -o $(NAME)

clean	:
	@rm -rf $(OBJS)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY	: all $(NAME) clean fclean re
