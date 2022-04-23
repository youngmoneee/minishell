#include "minishell.h"

int	minishell(void)
{
	char	*input;
	//char	**parsed_input;

	if (set_signal())
		return (1);
	while (1)
	{
		input = readline("minishell % ");
		if (input == 0)
			return (enter_ctrld());
		if (*input != '\0')
		{
			add_history(input);
			//parsed_input = parsing(input);
			//if (parsed_input == 0)
				// ERROR!!!
			// builtin command
			// execute program
		}
		free(input);
	}
	return (0);
}
