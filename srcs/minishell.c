/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:39 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/10 22:46:52 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(void)
{
	char	*input;
	t_elem	*parsed_input;
	int		elem_cnt;

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
			parsed_input = parsing_split(input, &elem_cnt);
			if (!(parsing_error(parsed_input, elem_cnt)
				|| env_transform(parsed_input, elem_cnt)
				|| quote_pairing(parsed_input, elem_cnt)))
			{
				// builtin command
				// execute program
				debug_print_elems(parsed_input, -1);
			}
			else
				printf("parsing error!!!!!\n");
		}
		free(input);
	}
	return (0);
}
