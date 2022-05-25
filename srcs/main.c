/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:40 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 16:03:33 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_banner2(void)
{
	ft_putstr_fd(2, "\033[0;91m"
		" \\__\\/  /~~/:/  /__/\\/:/~~  \\__\\/  |:|/:/  /__/\\/:/~~ "
		" \\  \\:\\ \\:\\_\\/ \\__\\/  \\:\\/:/ \\  \\:\\ \\:\\_\\/ "
		"\\  \\:\\    \\  \\:\\   \n");
	ft_putstr_fd(2, "\033[0;92m"
		"       /  /:/   \\  \\::/         |  |:/:/   \\  \\::/      "
		"\\  \\:\\_\\:\\        \\__\\::/   \\  \\:\\ \\:\\    \\  "
		"\\:\\    \\  \\:\\  \n");
	ft_putstr_fd(2, "\033[0;93m"
		"      /  /:/     \\  \\:\\         |__|::/     \\  \\:\\    "
		"   \\  \\:\\/:/        /  /:/     \\  \\:\\_\\/     \\  \\:"
		"\\    \\  \\:\\ \n");
	ft_putstr_fd(2, "\033[0;94m"
		"     /__/:/       \\__\\/         /__/:/       \\__\\/      "
		"  \\  \\::/        /__/:/       \\  \\:\\        \\  \\:\\ "
		"   \\  \\:\\\n");
	ft_putstr_fd(2, "\033[0;95m"
		"     \\__\\/                      \\__\\/                   "
		"   \\__\\/         \\__\\/         \\__\\/         \\__\\/ "
		"    \\__\\/\n");
}

static void	print_banner(void)
{
	ft_putstr_fd(2, "\033[0;31m"
		"      ___                        ___                        "
		"___           ___           ___           ___       ___ \n");
	ft_putstr_fd(2, "\033[0;32m"
		"     /  /\\           ___        /  /\\           ___       "
		" /  /\\         /  /\\         /  /\\         /  /\\     /  /\\\n");
	ft_putstr_fd(2, "\033[0;33m"
		"    /  /::|         /__/\\      /  /::|         /__/\\      "
		"/  /::\\       /  /:/        /  /::\\       /  /:/    /  /:/\n");
	ft_putstr_fd(2, "\033[0;34m"
		"   /  /:|:|         \\__\\:\\    /  /:|:|         \\__\\:\\ "
		"   /__/:/\\:\\     /  /:/        /  /:/\\:\\     /  /:/    /  /:/ \n");
	ft_putstr_fd(2, "\033[0;35m"
		"  /  /:/|:|__       /  /::\\  /  /:/|:|__       /  /::\\  _"
		"\\_ \\:\\ \\:\\   /  /::\\ ___   /  /::\\ \\:\\   /  /:/    /  /:/\n");
	ft_putstr_fd(2, "\033[0;36m"
		" /__/:/_|::::\\   __/  /:/\\/ /__/:/ |:| /\\   __/  /:/\\/ /"
		"__/\\ \\:\\ \\:\\ /__/:/\\:\\  /\\ /__/:/\\:\\ \\:\\ /__/:/ "
		"   /__/:/   \n");
	print_banner2();
	ft_putstr_fd(2, "\033[0;90m\n\t\t\t\t\t\t\t\t\t\t\t\t"
		"by. youngpar && dongkim\n\033[0m");
}

static int	init_main(t_stat *stat, char **envp)
{
	stat->pgname = SHELL_NAME;
	stat->print_err = -1;
	stat->std_fd[0] = dup(STDIN_FILENO);
	stat->std_fd[1] = dup(STDOUT_FILENO);
	stat->exist_heredoc_tmpfile = 0;
	stat->last_return = 0;
	stat->cmd_return = 0;
	stat->pipe_cnt = 0;
	stat->env = deep_copy(envp);
	if (stat->env == 0 || stat->std_fd[0] == -1 || stat->std_fd[1] == -1)
		return (MAIN_ERR_INIT);
	return (0);
}

static void	minishell_error(t_stat *stat)
{
	if (stat->print_err == MAIN_ERR_INIT)
		printf("%s: init error\n", stat->pgname);
	if (stat->print_err == MAIN_ERR_PARS)
		printf("%s: memory alloc error\n", stat->pgname);
	else
		return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_stat	stat;

	if (argc != 1)
		return (ARGV_ERR_RET);
	stat.print_err = init_main(&stat, envp);
	if (stat.print_err != MAIN_ERR_INIT)
	{
		if (argv)
			print_banner();
		stat.print_err = minishell(&stat);
	}
	minishell_error(&stat);
	clean_dchar(stat.env, -1);
	return (stat.last_return);
}
