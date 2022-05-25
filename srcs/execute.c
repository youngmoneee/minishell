/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:17:03 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 14:29:09 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_strcmp_igcase(char *s1, char *s2)
{
	int		i;
	char	c;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i])
	{
		c = s1[i];
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			c = s1[i] - 'A' + 'a';
		if (c != s2[i])
			return (c - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

static int	exec_builtin(t_lst *node, t_stat *stat)
{
	if (ft_strcmp_igcase(node->cmd, "echo") == 0)
		return (ft_echo(node->argc, node->argv));
	else if (ft_strcmp_igcase(node->cmd, "pwd") == 0)
		return (ft_pwd());
	else if (ft_strcmp_igcase(node->cmd, "env") == 0)
		return (ft_env(stat->env));
	else if (ft_strcmp_igcase(node->cmd, "cd") == 0)
		return (stat->pipe_cnt == 0
			&& ft_cd(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "export") == 0)
		return (stat->pipe_cnt == 0
			&& ft_export(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "unset") == 0)
		return (stat->pipe_cnt == 0
			&& ft_unset(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "exit") == 0)
		return (stat->pipe_cnt == 0
			&& ft_exit(node->argc, node->argv, stat));
	return (-1);
}

static int	execute(t_lst *input, t_stat *stat)
{
	int	ret;

	ret = exec_builtin(input, stat);
	if (ret == -1)
		ret = exec_program(input, stat);
	return (ret);
}

static void	print_fdopen_err(char *file, t_stat *stat)
{
	char	*msg;

	msg = strerror(errno);
	ft_builtin_error(stat->pgname, file, msg);
	stat->cmd_return = EXEC_ERR_FD;
}

int	execute_line(t_lst **input, t_stat *stat)
{
	int	cur_fd[2];
	int	pip_fd[2];
	int	fd_err_idx;
	int	i;

	i = 0;
	while (*input && stat->cmd_return != -1)
	{
		pipe(pip_fd);
		fd_err_idx = get_redirect_fd(*input, cur_fd, stat);
		if (fd_err_idx == -2)
			return (1);
		if (fd_err_idx != -1)
			print_fdopen_err((*input)->fdv[fd_err_idx].file, stat);
		set_input_file_redirect(i++, cur_fd, stat);
		set_output_redirect(*input, cur_fd, pip_fd, stat);
		if (fd_err_idx == -1 && (*input)->cmd && ft_strlen((*input)->cmd))
			stat->cmd_return = execute(*input, stat);
		rm_heredoc_tmpfile(stat);
		dup2(stat->std_fd[0], STDIN_FILENO);
		dup2(stat->std_fd[1], STDOUT_FILENO);
		del_node_front(input, 2);
		set_input_pipe_redirect(*input, pip_fd);
	}
	return (0);
}
