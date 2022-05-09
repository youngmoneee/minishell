/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:40 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/09 10:30:29 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_glob	g_val;

void	print_banner(char *argv[])
{
	printf("run %s\n", argv[0]);
}

int	main(int argc, char *argv[], char *env[])
{
	if (argc != 1)
		return (1);
	print_banner(argv);
	g_val.env = copy_env(env);
	if (m_env == 0)
		printf("copy env Error");
	else
	{
		echo(NULL);
		//adder("park", "youngseo");
		//adder("kim", "donghyun");
		printf("");
		minishell(m_env);
	}
	return (0);
}
