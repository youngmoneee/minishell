/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:18:51 by youngpar          #+#    #+#             */
/*   Updated: 2022/05/25 13:44:15 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# define BUFSIZE	1024
# define TRUE		1
# define FALSE		0

# define ET_STR	4
# define ET_LTS	8
# define ET_GTS	16
# define ET_PIP	32
# define HEREDOC_RDBYTE	5
# define HEREDOC_TMPFILE	"/tmp/minishell_heredoc_tmpfile"

# define SH_IGN	-1
# define SH_DFL	0
# define SH_SHELL	1
# define SH_EXIT	3

typedef int					t_bool;
typedef struct s_elem		t_elem;
typedef struct s_fd			t_fd;
typedef struct s_lst		t_lst;
typedef struct s_stat		t_stat;

struct s_elem
{
	char	*data;
	int		type;
	int		subtype;
};

struct s_fd
{
	char	*file;
	int		type;
	int		subtype;
};

struct s_lst
{
	char			*cmd;
	int				argc;
	char			**argv;
	int				fdc;
	struct s_fd		*fdv;
	struct s_lst	*next;
};

struct s_stat
{
	char	*pgname;
	int		std_fd[2];
	int		exist_heredoc_tmpfile;
	int		cmd_return;
	int		last_return;
	int		pipe_cnt;
	int		print_err;
	char	**env;
};

#endif
