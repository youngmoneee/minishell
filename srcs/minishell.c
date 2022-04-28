#include "minishell.h"

int	minishell(void)
{
	char	*input;
	t_elem	*parsed_input;

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
			parsed_input = parsing_split(input);
			if (parsing_error(parsed_input))
				printf("PARSING ERROR!!!\n");
			while (parsed_input->data != 0)
			{
				printf("%s\n", parsed_input->data);
				parsed_input++;
			}
			//if (parsed_input == 0)
				// ERROR!!!
			// builtin command
			// execute program
		}
		free(input);
	}
	return (0);
}
