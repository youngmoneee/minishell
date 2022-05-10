/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:39 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 00:51:24 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lst	*get_input_lst(char *input)
{
	t_elem	*elems;
	int		elem_cnt;
	t_lst	*lst;

	elems = parsing_split(input, &elem_cnt);
	debug_print_elems(elems, -1);
	if (elems == 0
		|| parsing_error(elems)
		|| env_transform(elems)
		|| quote_pairing(elems)
		|| elems_to_lst(elems, &lst))
	{
		clean_elem(elems, elem_cnt);
		printf("==== PARSING ERROR ====\n");
		return (0);
	}
	return (lst);
}

int	minishell(void)
{
	char	*input;
	t_lst	*parsed_input;

	if (set_signal())
		return (1);
	while (1)
	{
		input = readline("minishell % ");
		if (input == 0)
			return (enter_ctrld());
		if (*input != '\0')
		{
			add_history(input);
			parsed_input = get_input_lst(input);
			if (parsed_input)
			{
				printf("====== SUCCESS!!! ======= \n");
				// builtin command
				// execute program
			}
		}
		free(input);
	}
	return (0);
}
