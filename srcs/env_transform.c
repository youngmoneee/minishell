/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:32 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/04 05:44:12 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_env_length(const char *str)
{
	int	len;

	len = 0;
	while ((str[len] >= '0' && str[len] <= '9')
		|| (str[len] >= 'a' && str[len] <= 'z')
		|| (str[len] >= 'A' && str[len] <= 'Z'))
		len++;
	return (0);
}

char	*line_env_transform(const char *bef)
{
	char	quote;
	int		i;
	char	*ret;

	quote = 0;
	i = 0;
	while (bef[i])
	{
		if (quote && bef[i] == quote)
			quote = 0;
		if (quote == 0 && (bef[i] == '\'' || bef[i] == '\"'))
			quote = bef[i];
		if (quote != '\'' && bef[i] == '$')
		{
			env_klen = get_env_length(&bef[i]);
			ret = ft_strinsert(bef, i, getenv());
			if (
			// ft_strtcat으로 현재인덱스 이전까지의 문자열
		}
		i++;
	}
}

int	env_transform(t_elem *elems)
{
	int		i;
	char	*ret;

	i = 0;
	while (elems[i].data)
	{
		if (elems[i].type == ET_STR)
		{
			ret = line_env_transform(elems[i].data);
			if (ret == 0)
				return (1);
			free(elems[i].data);
			elems[i].data = ret;
		}
		i++;
	}
	return (0);
}

