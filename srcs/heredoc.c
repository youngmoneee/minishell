/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:38:09 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/24 17:55:41 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc_is_ended(char *input, int input_len, char *end, int end_len)
{
	int	i;

	if (input && input_len > end_len)
	{
		i = 0;
		while (i < end_len && input[input_len - 1 - end_len + i] == end[i])
			i++;
		if (i == end_len)
		{
			if (input_len > end_len + 1)
				if (input[input_len - 1 - end_len - 1] != '\n')
					return (0);
			input[input_len - 1 - end_len] = 0;
			return (1);
		}
	}
	return (0);
}

char	*heredoc_input(char *end, t_stat *stat)
{
	char	*input;
	int		len;
	int		total_len;

	total_len = 0;
	input = 0;
	len = 1;
	while (len != 0
		&& !heredoc_is_ended(input, total_len, end, ft_strlen(end)))
	{
		if (total_len == 0 || (total_len && input[total_len - 1] == '\n'))
			write(1, "> ", 2);
		input = ft_realloc(input, total_len, total_len + HEREDOC_RDBYTE + 1, 1);
		if (input == 0)
			return (0);
		len = read(stat->std_fd[0], &input[total_len], HEREDOC_RDBYTE);
		total_len += len;
	}
	return (input);
}

void	rm_heredoc_tmpfile(t_stat *stat)
{
	if (stat->exist_heredoc_tmpfile)
	{
		unlink(HEREDOC_TMPFILE);
		stat->exist_heredoc_tmpfile = 0;
	}
}
