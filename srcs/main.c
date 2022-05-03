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
	minishell(env);
	return (0);
}
