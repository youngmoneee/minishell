/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 00:10:44 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/23 17:29:17 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_input_file_redirect(int idx, int *cur_fd, t_stat *stat)
{
	if (cur_fd[0] == 0)
	{
		if (idx == 0)
			dup2(stat->std_fd[0], STDIN_FILENO);
	}
	else
	{
		dup2(cur_fd[0], STDIN_FILENO);
		close(cur_fd[0]);
	}
}

void	set_input_pipe_redirect(t_lst *node, int *pip_fd)
{
	if (node)
		dup2(pip_fd[0], STDIN_FILENO);
	close(pip_fd[0]);
}

void	set_output_redirect(t_lst *node, int *cur_fd, int *pip_fd, t_stat *stat)
{
	if (cur_fd[1] == 1)
	{
		if (node->next == 0)
			dup2(stat->std_fd[1], STDOUT_FILENO);
		else
			dup2(pip_fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(cur_fd[1], STDOUT_FILENO);
		close(cur_fd[1]);
	}
	close(pip_fd[1]);
}
