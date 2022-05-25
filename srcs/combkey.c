/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:55 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/24 17:50:52 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	signal_handler_exit(int signo)
{
	if (signo == SIGINT)
	{
		exit(1);
	}
}

void	unset_echoctl_termios(void)
{
	struct termios	term;

	tcgetattr(STDOUT_FILENO, &term);
	term.c_lflag &= (~ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSANOW, &term);
}

void	set_signal(int n_int, int n_quit)
{
	if (n_int == SH_IGN)
		signal(SIGINT, SIG_IGN);
	if (n_int == SH_DFL)
		signal(SIGINT, SIG_DFL);
	if (n_int == SH_SHELL)
		signal(SIGINT, signal_handler);
	if (n_int == SH_EXIT)
		signal(SIGINT, signal_handler_exit);
	if (n_quit == SH_IGN)
		signal(SIGQUIT, SIG_IGN);
	if (n_quit == SH_DFL)
		signal(SIGQUIT, SIG_DFL);
	if (n_quit == SH_SHELL)
		signal(SIGQUIT, signal_handler);
}

int	enter_ctrld(void)
{
	printf("\x1b[1A");
	rl_on_new_line();
	rl_redisplay();
	printf("exit\n");
	return (1);
}
