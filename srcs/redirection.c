/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:26:07 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 02:10:10 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fork_heredoc(t_fd *fd, t_stat *stat)
{
	char	*input;
	int		fd_in;
	pid_t	pid;

	set_signal(SH_EXIT, SH_IGN);
	pid = fork();
	if (pid == 0)
	{
		input = heredoc_input(fd->file, stat);
		if (input == 0)
			exit(2);
		input = line_env_transform(input, 1, stat);
		if (input == 0)
			exit(2);
		fd_in = open(HEREDOC_TMPFILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
		if (fd_in != -1)
			write(fd_in, input, ft_strlen(input));
		free(input);
		close(fd_in);
		exit(0);
	}
	set_signal(SH_IGN, SH_IGN);
	wait(&fd_in);
	set_signal(SH_SHELL, SH_IGN);
	return (fd_in >> 8);
}

static int	redirect_input(t_fd *fd, t_stat *stat)
{
	int		fd_in;
	int		ret;

	if (fd->subtype == 1)
		fd_in = open(fd->file, O_RDONLY | O_EXCL);
	else
	{
		ret = fork_heredoc(fd, stat);
		stat->cmd_return = ret;
		if (ret == 1)
			return (-2);
		if (ret != 0)
			return (-1);
		stat->exist_heredoc_tmpfile = 1;
		fd_in = open(HEREDOC_TMPFILE, O_RDONLY | O_EXCL);
	}
	return (fd_in);
}

static int	redirect_output(t_fd *fd)
{
	int	fd_out;

	if (fd->subtype == 1)
		fd_out = open(fd->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd_out = open(fd->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd_out);
}

int	get_redirect_fd(t_lst *node, int *cur_fd, t_stat *stat)
{
	int	i;

	cur_fd[1] = 1;
	cur_fd[0] = 0;
	i = -1;
	while (++i < node->fdc)
	{
		if (node->fdv[i].type == ET_GTS)
		{
			if (cur_fd[1] != STDOUT_FILENO)
				close(cur_fd[1]);
			cur_fd[1] = redirect_output(&node->fdv[i]);
		}
		if (node->fdv[i].type == ET_LTS)
		{
			if (cur_fd[0] != STDIN_FILENO)
				close(cur_fd[0]);
			cur_fd[0] = redirect_input(&node->fdv[i], stat);
		}
		if (cur_fd[0] == -2)
			return (-2);
		if (cur_fd[1] == -1 || cur_fd[0] == -1)
			return (i);
	}
	return (-1);
}
