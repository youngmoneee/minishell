#include "minishell.h"

int	is_special(const char *str, t_elem *elem)
{
	int	ret;

	ret = 0;
	elem->type = ET_STR;
	if (*str == '<')
	{
		if (*(str + 1) == '<')
			ret = 2;
		ret = 1;
		elem->type = ET_LTS;
	}
	if (*str == '>')
	{
		if (*(str + 1) == '>')
			ret = 2;
		ret = 1;
		elem->type = ET_GTS;
	}
	if (*str == '|')
	{
		ret = 1;
		elem->type = ET_PIP;
	}
	return (ret);
}

int	get_elem(const char *str, t_elem *elem)
{
	int		len;
	char	delim;

	len = is_special(str, elem);
	if (len == 0)
	{
		while (str[len] && str[len] != ' '
			&& str[len] != '<' && str[len] != '>' && str[len] != '|')
		{
			if (str[len] == '\'' || str[len] == '\"')
			{
				delim = str[len++];
				while (str[len] && str[len] != delim)
					len++;
				if (str[len] == 0)
					len--;
			}
			len++;
		}
	}
	elem->data = ft_makestr(str, len);
	if (elem->data == 0)
		return (-1);
	return (len);
}

t_elem	*clean_elem(t_elem *elems, int cnt)
{
	int	i;

	if (elems)
	{
		i = 0;
		while (i < cnt)
		{
			free(elems[i].data);
			i++;
		}
		free(elems);
	}
	return (0);
}

t_elem	*parsing_split(const char *str)
{
	t_elem	*ret;
	t_elem	*bef;
	int		cnt;
	int		len;

	cnt = 1;
	bef = 0;
	while (*str)
	{
		ret = (t_elem *)ft_realloc((char *)bef,
				sizeof(t_elem) * cnt, sizeof(t_elem) * (cnt + 1));
		if (ret == 0)
			return (clean_elem(bef, cnt - 1));
		while (*str == ' ')
			str++;
		len = get_elem(str, &ret[cnt - 1]);
		if (len == -1)
			return (clean_elem(ret, cnt - 1));
		str += len;
		bef = ret;
		while (*str == ' ')
			str++;
		cnt++;
	}
	return (ret);
}
