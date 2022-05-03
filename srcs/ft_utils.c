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

void	ft_strncpy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

void    *clean_elem(t_elem *elems)
{
    int i;

    if (elems)
    {
        i = 0;
        while (elems[i].data)
        {
            free(elems[i].data);
            i++;
        }
        free(elems);
    }
    return (0);
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
