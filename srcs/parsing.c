/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:03:48 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 13:56:50 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_space_idx(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	return (i);
}

int	parsing_error(t_elem *elems, t_stat *stat)
{
	int	i;
	int	schar;
	int	last_type;

	i = 0;
	schar = 0;
	if (elems[0].type == ET_PIP)
	{
		stat->print_err = 0;
		return (1);
	}
	while (elems[i].data && schar < 2)
	{
		last_type = elems[i++].type;
		if (last_type == ET_STR && schar == 1)
			schar = 0;
		if (last_type != ET_STR)
			schar++;
	}
	if (!(schar > 1 || last_type != ET_STR))
		return (0);
	stat->print_err = i - 1;
	return (1);
}

static int	is_special(const char *str, t_elem *elem, t_stat *stat)
{
	int	ret;

	ret = 0;
	elem->type = ET_STR;
	if (*str == '<' || *str == '>' || *str == '|')
		ret = 1;
	if (*str == '<')
	{
		if (*(str + 1) == '<')
			ret = 2;
		elem->type = ET_LTS;
	}
	if (*str == '>')
	{
		if (*(str + 1) == '>')
			ret = 2;
		elem->type = ET_GTS;
	}
	if (*str == '|')
	{
		stat->pipe_cnt++;
		elem->type = ET_PIP;
	}
	elem->subtype = ret;
	return (ret);
}

static int	get_elem(const char *str, t_elem *elem, t_stat *stat)
{
	int	len;

	len = is_special(str, elem, stat);
	if (len == 0)
	{
		while (str[len] && get_space_idx(&str[len]) == 0
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

t_elem	*parsing_split(const char *str, int *cnt, t_stat *stat)
{
	t_elem	*ret;
	t_elem	*bef;
	int		len;

	*cnt = 0;
	bef = 0;
	while (*str)
	{
		ret = (t_elem *)ft_realloc(bef,
				sizeof(t_elem) * (*cnt + 1), sizeof(t_elem) * (*cnt + 2), 0);
		if (ret == 0)
			return (clean_elem(bef, *cnt));
		str += get_space_idx(str);
		len = get_elem(str, &ret[*cnt], stat);
		if (len == -1)
			return (clean_elem(ret, *cnt));
		str += len;
		free(bef);
		bef = ret;
		str += get_space_idx(str);
		(*cnt)++;
	}
	return (ret);
}
