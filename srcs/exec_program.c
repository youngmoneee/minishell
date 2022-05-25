/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:10:17 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 02:09:55 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*find_path(char *cmd, t_stat *stat)
{
	char	**split_path;
	int		i;
	char	*path;

	split_path = ft_split(ft_getenv("PATH", stat->env), ':');
	if (split_path == 0)
		return (0);
	i = 0;
	while (split_path[i])
	{
		path = ft_strtjoin(split_path[i], "/", cmd);
		if (path == 0)
			return (clean_dchar(split_path, -1));
		if (open(path, O_EXCL) != -1)
		{
			clean_dchar(split_path, -1);
			return (path);
		}
		free(path);
		i++;
	}
	clean_dchar(split_path, -1);
	return (cmd);
}

static void	print_exec_err(int i, char *cmd, t_stat *stat)
{
	char	*msg;

	if (i == ft_strlen(cmd))
		msg = "command not found";
	else
		msg = strerror(errno);
	ft_builtin_error(stat->pgname, cmd, msg);
}

int	exec_program(t_lst *node, t_stat *stat)
{
	pid_t	pid;
	int		fork_ret;
	int		i;

	fork_ret = 0;
	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (node->cmd[i] && node->cmd[i] != '/')
			i++;
		if (i == ft_strlen(node->cmd))
			node->cmd = find_path(node->cmd, stat);
		execve(node->cmd, node->argv, stat->env);
		print_exec_err(i, node->cmd, stat);
		exit(EXEC_ERR_CMDNF);
	}
	set_signal(SH_IGN, SH_IGN);
	wait(&fork_ret);
	set_signal(SH_SHELL, SH_IGN);
	return (fork_ret >> 8);
}
