/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:40:27 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 14:33:03 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <limits.h>

static void	exit_numeric(char *arg, unsigned char error_number)
{
	ft_builtin_error4(SHELL_NAME, "exit", arg, "numeric argument required");
	exit(error_number);
}

static void	ft_exit_atoi(char *arg)
{
	int			ret;
	int			flag;
	long long	sum;

	ret = -1;
	flag = 1;
	if (arg[0] == '+' || arg[0] == '-')
	{
		if (arg[0] == '-')
			flag = -1;
		ret = 0;
	}
	sum = 0;
	while (arg[++ret])
	{
		if (arg[ret] < '0' || arg[ret] > '9')
			exit_numeric(arg, -1);
		if ((sum * flag == -922337203685477580 && arg[ret] > '8')
			|| (sum * flag == 922337203685477580 && arg[ret] > '7')
			|| sum * flag <= -922337203685477581
			|| sum * flag >= 922337203685477581)
			exit_numeric(arg, -1);
		sum = sum * 10 + arg[ret] - '0';
	}
	exit(sum * flag);
}

int	ft_exit(const int argc, char **argv, t_stat *stat)
{
	ft_putstr_fd(2, "exit\n");
	if (argc > 2)
	{
		ft_builtin_error(SHELL_NAME, "exit", "too many arguments");
		return (1);
	}
	if (argc == 1)
		exit(stat->last_return);
	ft_exit_atoi(argv[1]);
	return (0);
}
