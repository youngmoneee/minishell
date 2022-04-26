#include "minishell.h"

char	*ft_realloc(char *ptr, int befsize, int aftsize)
{
	char	*ret;
	int		i;

	ret = malloc(aftsize);
	if (ret)
	{
		i = 0;
		while (ptr && i < befsize)
		{
			ret[i] = ptr[i];
			i++;
		}
		while (i < aftsize)
			ret[i++] = 0;
		if (ptr)
			free(ptr);
	}
	return (ret);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_makestr(const char *str, int len)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	ret[len] = 0;
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

/*
int		division(char *str, unsigned char delim)
{
	int	len;

	len = 0;
	while (str[len]
		&& ((delim == '$' && str[len] >= '0' && str[len] <= '9'
		&& str[len] >= 'a' && str[len] <= 'z'
		&& str[len] >= 'A' && str[len] <= 'Z'
		|| (delim != '$' && str[len] != delim))))
	{
		len++;
	}
	return (len);
}*/
