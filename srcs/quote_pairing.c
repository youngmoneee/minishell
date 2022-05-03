#include "minishell.h"

static void	cp_without_quote(char *dst, char *src)
{
	int		i;
	char	quot;

	i = 0;
	while (*src)
	{
		if (*src == '\'' || *src == '\"')
		{
			quot = *(src++);
			while (quot != *src)
				dst[i++] = *(src++);
		}
		else
			dst[i++] = *src;
		src++;
	}
	dst[i] = 0;
}

int	quote_pairing(t_elem *elems)
{
	char	*bef;
	char	*aft;

	while (elems->data)
	{
		bef = elems->data;
		aft = malloc(sizeof(char) * (ft_strlen(bef) + 1));
		if (aft == 0)
			return (clean_elem(elems) == 0);
		cp_without_quote(aft, bef);
		elems->data = aft;
		free(bef);
		elems++;
	}
	return (0);
}
