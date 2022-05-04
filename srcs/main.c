/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:40 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/04 03:38:39 by dongkim          ###   ########.fr       */
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
	echo(NULL);
<<<<<<< HEAD
	minishell(env);
=======
	adder("park", "youngseo");
	adder("kim", "donghyun");
	printf("");
	minishell();
>>>>>>> e702f74bfbad20a155b3a3cda93d08f8ea9929b1
	return (0);
}
