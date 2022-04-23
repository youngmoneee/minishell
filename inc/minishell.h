#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TY_STR	0
# define TY_SPE	1

typedef struct	s_elem {
	char	*data;
	int		type;
} t_elem

int		set_signal(void);
int		enter_ctrld(void);

int		minishell(void);

void	*ft_realloc(void *ptr, int befsize, int aftsize);

#endif
