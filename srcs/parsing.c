/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:48 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/05 02:18:18 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_quote_len(const char *str)
{
	char	quote;
	int		len;

	quote = *str;
	if (quote == '\'' || quote == '\"')
	{
		len = 1;
		while (str[len] && quote != str[len])
			len++;
		return (len);
	}
	return (0);
}

int	parsing_error(t_elem *elems)
{
	int	i;
	int	j;
	int	schar;
	int	last_type;

	i = 0;
	schar = 0;
	while (elems[i].data)
	{
		last_type = elems[i++].type;
		if (last_type == ET_STR && schar == 1)
			schar = 0;
		if (last_type != ET_STR)
			schar++;
	}
	j = 0;
	while (elems[i - 1].data[j])
	{
		j += get_quote_len(&elems[i - 1].data[j]);
		if (elems[i - 1].data[j] == 0)
			return (1);
		j++;
	}
	return (schar > 1 || last_type == ET_LTS || last_type == ET_GTS);
}

static int	is_special(const char *str, t_elem *elem)
{
	int	ret;

	ret = 0;
	elem->type = ET_STR;
	if (*str == '<')
	{
		ret = 1;
		if (*(str + 1) == '<')
			ret = 2;
		elem->type = ET_LTS;
	}
	if (*str == '>')
	{
		ret = 1;
		if (*(str + 1) == '>')
			ret = 2;
		elem->type = ET_GTS;
	}
	if (*str == '|')
	{
		ret = 1;
		elem->type = ET_PIP;
	}
	return (ret);
}

static int	get_elem(const char *str, t_elem *elem)
{
	int	len;

	len = is_special(str, elem);
	if (len == 0)
	{
		while (str[len] && str[len] != ' '
			&& str[len] != '<' && str[len] != '>' && str[len] != '|')
		{
			if (str[len] == '\'' || str[len] == '\"')
				len += get_quote_len(&str[len]);
			if (str[len])
				len++;
		}
	}
	elem->data = malloc(sizeof(char) * (len + 1));
	if (elem->data == 0)
		return (-1);
	ft_strncpy(elem->data, str, len);
	return (len);
}

t_elem	*parsing_split(const char *str, int *cnt)
{
	t_elem	*ret;
	t_elem	*bef;
	int		len;

	*cnt = 1;
	bef = 0;
	while (*str)
	{
		ret = (t_elem *)ft_realloc((char *)bef,
				sizeof(t_elem) * (*cnt), sizeof(t_elem) * ((*cnt) + 1));
		if (ret == 0)
			return (clean_elem(bef, *cnt));
		while (*str == ' ')
			str++;
		len = get_elem(str, &ret[(*cnt) - 1]);
		if (len == -1)
			return (clean_elem(ret, *cnt));
		str += len;
		bef = ret;
		while (*str == ' ')
			str++;
		(*cnt)++;
	}
	return (ret);
}
