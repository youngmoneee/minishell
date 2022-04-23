#include "minishell.h"

void	*ft_realloc(void *ptr, int befsize, int aftsize)
{
	void	*ret;
	int		i;

	ret = malloc(aftsize);
	if (ret)
	{
		i = 0;
		while (ptr && i < befsize)
			ret[i++] = ptr[i];
		while (i < aftsize)
			ret[i++] = 0;
		if (ptr)
			free(ptr);
	}
	return (ret);
}
