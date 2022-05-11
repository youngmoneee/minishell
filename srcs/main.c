/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:40 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 17:20:10 by dongkim          ###   ########.fr       */
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
	if (g_val.env == 0)
		printf("copy env Error");
	else
	{
		echo(NULL);
		minishell();
	}
	clean_dchar(g_val.env, g_val.env_len);
	return (0);
}
