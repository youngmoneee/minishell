/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:17:03 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 13:11:22 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	exec_builtin(t_lst *node)
{
	if (ft_strcmp(node->argv[0], "echo"))
	else if (ft_strcmp(node->argv[0], "cd"))
	else if (ft_strcmp(node->argv[0], "pwd"))
	else if (ft_strcmp(node->argv[0], "export")
	else if (ft_strcmp(node->argv[0], "unset"))
	else if (ft_strcmp(node->argv[0], "env"))
	else if (ft_strcmp(node->argv[0], "exit"))
}

int	execute_line(t_lst *input)
{
	while (input)
	{
		if (input->type == 1)
		{
			exec_builtin(input);
		}
		else
		{
		}
		del_node_front(&input, 2);
	}
}
