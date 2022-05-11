/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:10:19 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/11 17:20:51 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **env)
{
	char	**ret;
	int		i;

	g_val.env_len = 0;
	while (env[g_val.env_len])
		g_val.env_len++;
	ret = malloc(sizeof(char *) * (g_val.env_len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < g_val.env_len)
	{
		ret[i] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		if (ret[i] == 0)
			return (clean_dchar(ret, i));
		ft_strncpy(ret[i], env[i], ft_strlen(env[i]));
		i++;
	}
	return (ret);
}

static int	get_env_idx(char *name)
{
	int	i;
	int	j;

	i = 0;
	while (g_val.env[i])
	{
		j = 0;
		while (g_val.env[i][j] != '=' && g_val.env[i][j] == name[j])
			j++;
		if (g_val.env[i][j] == '=' && name[j] == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_env(char *name)
{
	int	i;
	int	j;

	i = get_env_idx(name);
	if (i >= 0)
	{
		j = 0;
		while (g_val.env[i][j] != '=')
			j++;
		return (&g_val.env[i][j + 1]);
	}
	return (0);
}

int	put_env(char *varname)
{
	int		i;
	char	**new_env;

	new_env = malloc(sizeof(char *) * (g_val.env_len + 2));
	if (new_env == 0)
		return (-1);
	i = 0;
	while (g_val.env[i])
	{
		new_env[i] = g_val.env[i];
		i++;
	}
	new_env[i] = varname;
	new_env[i + 1] = 0;
	free(g_val.env);
	g_val.env = new_env;
	g_val.env_len++;
	return (0);
}

int	remove_env(char *name)
{
	int		i;

	i = get_env_idx(name);
	if (i >= 0)
	{
		while (g_val.env[i])
		{
			g_val.env[i] = g_val.env[i + 1];
			i++;
		}
	}
	return (0);
}
