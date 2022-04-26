#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "structure.h"
# include "../libs/include/libs.h"

# define ET_STR	0
# define ET_SPE	1

int		set_signal(void);
int		enter_ctrld(void);

t_elem	*parsing_split(const char *str);

int		minishell(void);

char	*ft_realloc(char *ptr, int befsize, int aftsize);
int		ft_strlen(const char *str);
char	*ft_makestr(const char *str, int len);

#endif
