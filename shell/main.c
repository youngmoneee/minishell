/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:40:24 by youngpar          #+#    #+#             */
/*   Updated: 2022/04/22 22:41:37 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char	*input;

	while (1)
	{
		//	signal handler
		input = readline("minishell % ");
		if (input == 0)
			return (1);
		printf("line : %s\n", input);
		add_history(input);
		//	add history
		//	parse command
		//	builtin command
		//	execute program
		free(input);
		input = 0;
	}
	return (0);
}
