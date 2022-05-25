/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 04:11:34 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 21:28:14 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "debug.h"
# include "ft_errno.h"
# include "structure.h"
# include "../libs/include/libs.h"

# define SHELL_NAME	"minishell"

void	unset_echoctl_termios(void);
void	set_signal(int n_int, int n_quit);
int		enter_ctrld(void);

t_elem	*parsing_split(const char *str, int *cnt, t_stat *stat);
int		parsing_error(t_elem *elems, t_stat *stat);
char	*line_env_transform(char *str, int interpret_squot, t_stat *stat);
int		env_transform(t_elem *elems, t_stat *stat);
int		quote_pairing(t_elem *elems);
int		elems_to_lst(t_elem *elems, int elem_cnt, t_lst **lst);

int		del_node_front(t_lst **head, int is_deep_clean);

char	*heredoc_input(char *end, t_stat *stat);
void	rm_heredoc_tmpfile(t_stat *stat);
int		get_redirect_fd(t_lst *node, int *cur_fd, t_stat *stat);
void	set_input_file_redirect(int idx, int *cur_fd, t_stat *stat);
void	set_input_pipe_redirect(t_lst *node, int *pip_fd);
void	set_output_redirect(t_lst *node, int *cur_fd,
			int *pip_fd, t_stat *stat);

int		exec_program(t_lst *node, t_stat *stat);
int		execute_line(t_lst **input, t_stat *stat);
int		minishell(t_stat *stat);

#endif
