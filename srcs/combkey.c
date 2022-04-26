#include "minishell.h"

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
	}
	rl_on_new_line();
	rl_redisplay();
}

int	set_signal(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		return (1);
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		return (1);
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (1);
	if (signal(SIGQUIT, signal_handler) == SIG_ERR)
		return (1);
	return (0);
}

int	enter_ctrld(void)
{
	printf("\x1b[1A");
	rl_on_new_line();
	rl_redisplay();
	printf("exit\n");
	return (1);
}
