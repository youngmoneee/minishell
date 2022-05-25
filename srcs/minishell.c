/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:39 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 14:08:22 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_parse_err(t_elem *elems, t_stat *stat)
{
	char	*msg;

	msg = "syntax error near unexpected token";
	stat->cmd_return = PARS_ERR_RET;
	if (elems[stat->print_err].type == ET_PIP)
		ft_parsing_error(stat->pgname, msg, "|");
	else if (stat->print_err == 0)
		ft_parsing_error(stat->pgname, msg, "newline");
	else if (elems[stat->print_err - 1].type == ET_PIP)
		ft_parsing_error(stat->pgname, msg, "|");
	else if (elems[stat->print_err - 1].type == ET_STR)
		ft_parsing_error(stat->pgname, msg, "newline");
	else
		ft_parsing_error(stat->pgname, msg, elems[stat->print_err].data);
}

static t_lst	*get_input_lst(char *input, t_stat *stat)
{
	t_elem	*elems;
	int		elem_cnt;
	t_lst	*lst;

	lst = 0;
	elems = parsing_split(input, &elem_cnt, stat);
	if (elems == 0
		|| parsing_error(elems, stat)
		|| env_transform(elems, stat)
		|| quote_pairing(elems)
		|| elems_to_lst(elems, elem_cnt, &lst))
	{
		if (stat->print_err >= 0)
			print_parse_err(elems, stat);
		else
			stat->print_err = MAIN_ERR_PARS;
		clean_elem(elems, elem_cnt);
		return (0);
	}
	return (lst);
}

static void	init_minishell(t_stat *stat)
{
	stat->pipe_cnt = 0;
	stat->print_err = -1;
}

int	minishell(t_stat *stat)
{
	char	*input;
	t_lst	*parsed_input;

	unset_echoctl_termios();
	set_signal(SH_SHELL, SH_IGN);
	while (1)
	{
		input = readline("minishell % ");
		if (input == 0)
			return (enter_ctrld());
		if (*input != '\0')
		{
			init_minishell(stat);
			add_history(input);
			parsed_input = get_input_lst(input, stat);
			if (parsed_input)
				execute_line(&parsed_input, stat);
			while (del_node_front(&parsed_input, 2))
				;
			stat->last_return = stat->cmd_return;
		}
		free(input);
	}
	return (stat->print_err);
}
