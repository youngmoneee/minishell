/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 04:11:34 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/10 22:36:55 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# include "debug.h"

# define TRUE	1
# define FALSE	0

# define ET_STR	0
# define ET_LTS	1
# define ET_GTS	2
# define ET_PIP	3

int		set_signal(void);
int		enter_ctrld(void);

t_elem	*parsing_split(const char *str, int *cnt);
int		parsing_error(t_elem *elems, int cnt);
int		env_transform(t_elem *elems, int cnt);
int		quote_pairing(t_elem *elems, int cnt);

int		minishell(void);

/*
 * env_utils
 */
char	**copy_env(char **env);
char	*get_env(char *name);
int		put_env(char *varname);
int		remove_env(char *name);

/*
 * ft_utils
 */
char	*ft_realloc(char *ptr, int befsize, int aftsize);
int		ft_strlen(const char *str);
void	ft_strncpy(char *dst, const char *src, int len);
char	*ft_replace(char *str, int idx, char *insert, int cutlen);
int		ft_strcmp(const char *s1, const char *s2);

void	*clean_elem(t_elem *elems, int cnt);
void	*clean_dchar(char **dchar, int cnt);

#endif
