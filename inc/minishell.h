/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 04:11:34 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/05 02:31:15 by dongkim          ###   ########.fr       */
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

<<<<<<< HEAD
# include "debug.h"
=======
# define TRUE	1
# define FALSE	0
>>>>>>> e702f74bfbad20a155b3a3cda93d08f8ea9929b1

# define ET_STR	0
# define ET_LTS	1
# define ET_GTS	2
# define ET_PIP	3

int		set_signal(void);
int		enter_ctrld(void);

t_elem	*parsing_split(const char *str, int *cnt);
int		parsing_error(t_elem *elems);
int		env_transform(t_elem *elems);
int		quote_pairing(t_elem *elems);

int		minishell(char *env[]);


/*
 * ft_utils
 */
char	*ft_realloc(char *ptr, int befsize, int aftsize);
int		ft_strlen(const char *str);
<<<<<<< HEAD
void	ft_strncpy(char *dst, const char *src, int len);
char	*ft_replace(char *str, int idx, char *insert, int cutlen);
void	*clean_elem(t_elem *elems, int cnt);
=======
char	*ft_makestr(const char *str, int len);
int		ft_strcmp(const char *s1, const char *s2);
>>>>>>> e702f74bfbad20a155b3a3cda93d08f8ea9929b1

#endif
