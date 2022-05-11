/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:17:03 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 07:25:10 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_builtin(t_lst *node)
{
	
}

int	execute_line(t_lst *input)
{
	while (input)
	{
		if (input->type == 1)
		{
			if (is_builtin())
			{
			}
			else
			{
			}
		}
		else
		{
		}
		del_node_front(&input, 2);
	}
}
