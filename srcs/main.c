#include "minishell.h"

void	print_banner(char *argv[])
{
	printf("run %s\n", argv[0]);
}

int	main(int argc, char *argv[])
{
	if (argc != 1)
		return (1);
	print_banner(argv);
	minishell();
	return (0);
}
