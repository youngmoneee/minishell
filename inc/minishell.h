#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ET_STR	0
# define ET_LTS	1
# define ET_GTS	2
# define ET_PIP	3

typedef struct s_elem {
	char	*data;
	int		type;
}	t_elem;

int		set_signal(void);
int		enter_ctrld(void);

int		parsing_error(t_elem *elems);
t_elem	*parsing_split(const char *str);

int		minishell(void);

char	*ft_realloc(char *ptr, int befsize, int aftsize);
int		ft_strlen(const char *str);
char	*ft_makestr(const char *str, int len);

#endif
