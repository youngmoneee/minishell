NAME=minishell
CC=gcc
CFLAGS=-Werror -Wall -Wextra
INC=-I ./inc
RLINC=-I/opt/homebrew/opt/readline/include
RLLIB=-L/opt/homebrew/opt/readline/lib -lreadline
SRCS=srcs/main.c\
	 srcs/combkey.c\
	 srcs/minishell.c\

.PHONY: all, re, clean, fclean

OBJS=$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(RLINC) $(CFLAGS) $(INC) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(RLLIB) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
