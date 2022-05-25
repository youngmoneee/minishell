# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 21:45:14 by youngpar          #+#    #+#              #
#    Updated: 2022/05/25 14:45:21 by dongkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIB		= libbuiltin.a

LDLIBS	= -lreadline \
		  -lbuiltin

CRLDIR	= ~/.brew/opt/readline/
RLDIR	= $(CRLDIR)
RLINC	= $(RLDIR)/include

LIBDIR	= -L $(RLDIR)/lib \
		  -L./libs

INCDIR	= -I ./inc \
		  -I $(RLINC)

SHDIR	= ./srcs
SHFILE	= main.c \
		  combkey.c \
		  parsing.c \
		  quote_pairing.c \
		  elems_to_lst.c \
		  env_transform.c\
		  exec_program.c \
		  execute.c \
		  heredoc.c \
		  redirection.c \
		  set_redirection.c \
		  minishell.c \

SRCS	= $(addprefix $(SHDIR)/, $(SHFILE))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CLFAGS) $(OBJS) $(LIBDIR) $(LDLIBS) -o $(NAME)

$(LIB)	:
	@make -C libs

clean	:
	@rm -rf $(OBJS)
	@make -C libs clean

fclean	: clean
	@rm -rf $(NAME)
	@make -C libs fclean

re		: fclean all

recomp	:
	@rm -rf $(NAME) $(OBJS)
	@make $(NAME)

.PHONY	: all clean fclean re recomp
