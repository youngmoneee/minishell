#include "minishell.h"

int	print_error(char *print, t_elem *elems, char *str)
{
	printf("%s", print);
	clean_elem(elems);
	free(str);
	return (1);
}

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
			if (parsing_error(parsed_input)) // error check
				return (print_error("PARSING ERROR!!!\n", parsed_input, input));
			// if (variable transform)
			//	 printf("PARSING ERROR3333!!!\n");
			if (quote_pairing(parsed_input))
				return (print_error("PARSING ERROR!!!\n", parsed_input, input));
			// builtin command
			// execute program
			while (parsed_input->data != 0)
			{
				printf("%s\n", parsed_input->data);
				parsed_input++;
			}
		}
		clean_elem(parsed_input);
		free(input);
	}
	return (0);
}
