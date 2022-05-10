/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 03:04:32 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 00:52:55 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_name(const char *str, int *len)
{
	char	*ret;

	*len = 1;
	while ((str[*len] >= '0' && str[*len] <= '9')
		|| (str[*len] >= 'a' && str[*len] <= 'z')
		|| (str[*len] >= 'A' && str[*len] <= 'Z'))
		(*len)++;
	if (*len > 1)
	{
		ret = malloc(sizeof(char) * (*len));
		if (ret == 0)
			return (0);
		ft_strncpy(ret, &str[1], (*len) - 1);
		return (ret);
	}
	else
	{
		*len = 0;
		return (0);
	}
}

static char	*env_replace(char *str, int *idx)
{
	int		env_klen;
	int		env_vlen;
	char	*env[2];
	char	*ret;

	env[0] = get_env_name(&str[*idx], &env_klen);
	if (env_klen == 0)
		return (str);
	if (env[0] == 0)
		return (0);
	env[1] = get_env(env[0]);
	free(env[0]);
	if (env[1] == 0)
		env[1] = "";
	ret = ft_replace(str, *idx, env[1], env_klen);
	env_vlen = ft_strlen(env[1]);
	if (ret == 0)
		return (0);
	free(str);
	*idx += env_vlen - 1;
	return (ret);
}

static char	*line_env_transform(char *str)
{
	char	quote;
	int		i;

	quote = 0;
	i = 0;
	while (str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else if (quote != '\'' && str[i] == '$')
		{
			str = env_replace(str, &i);
			if (str == 0)
				return (0);
		}
		i++;
	}
	return (str);
}

int	env_transform(t_elem *elems)
{
	int		i;
	char	*ret;

	printf("-> env_trasnform\n");
	i = 0;
	while (elems[i].data)
	{
		if (elems[i].type == ET_STR)
		{
			ret = line_env_transform(elems[i].data);
			if (ret == 0)
				return (1);
			elems[i].data = ret;
		}
		i++;
	}
	return (0);
}
