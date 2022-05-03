/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:39 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/04 04:41:07 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(char *env[])
{
	env = 0;
	char	*input;
	t_elem	*parsed_input;
	int		i;

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
			parsed_input = parsing_split(input);
			if (!(parsing_error(parsed_input)
				// || env transform(parsed_input)
				|| quote_pairing(parsed_input)))
			{
				// builtin command
				// execute program
			}
			else
				printf("parsing error!!!!!\n");
			i = 0;
			while (parsed_input[i].data != 0)
			{
				printf("%s\n", parsed_input[i].data);
				i++;
			}
			clean_elem(parsed_input);
		}
		free(input);
	}
	return (0);
}
