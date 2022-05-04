/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:39 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/05 02:42:34 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(char *env[])
{
	env = 0;
	char	*input;
	t_elem	*parsed_input;
	int		cnt;

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
			parsed_input = parsing_split(input, &cnt);
			if (!(parsing_error(parsed_input)
				|| env_transform(parsed_input)
				))//|| quote_pairing(parsed_input)))
			{
				// builtin command
				// execute program
			}
			else
				printf("parsing error!!!!!\n");
			debug_print_elems(parsed_input, -1);
			clean_elem(parsed_input, cnt - 1);
		}
		free(input);
	}
	return (0);
}
