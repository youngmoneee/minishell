#include "minishell.h"

int		get_elem(char *str, t_elem *elem)
{

	return (0);
}

int		clean_elem(t_elem *elems, int cnt)
{
	int	i;

	if (elems)
	{
		i = 0;
		while (i < cnt - 1)
		{
			free(elems[i].data);
			i++;
		}
		free(elems);
	}
	return (0);
}

t_elem	*parsing(const char *str)
{
	t_elem	*ret
	t_elem	*bef;
	int		cnt;
	int		len;

	cnt = 0;
	bef = 0;
	while (*str)
	{
		cnt++;
		ret = (t_elem *)ft_realloc(bef,
			sizeof(t_elem) * cnt, sizeof(t_elem) * (cnt + 1));
		if (ret == 0)
			return (ft_clean_dptr(bef, cnt));
		while (*str == ' ')
			str++;
		len = get_elem(&ret[cnt - 1], str);
		str += len;
		bef = ret;
		while (*str == ' ')
			str++;
	}
	return (ret);
}
