/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:10:19 by dongkim           #+#    #+#             */
/*   Updated: 2022/05/25 12:34:04 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/util.h"
#include "../../inc/structure.h"

char	**shallow_copy(char **arr)
{
	char	**ret;
	int		idx;

	idx = 0;
	while (arr[idx])
		idx++;
	ret = (char **)malloc(sizeof(char *) * (idx + 1));
	if (ret == NULL)
		return (0);
	idx = -1;
	while (arr[++idx])
		ret[idx] = arr[idx];
	ret[idx] = 0;
	return (ret);
}

char	**deep_copy(char **arr)
{
	char	**ret;
	int		idx;

	idx = 0;
	while (arr[idx])
		idx++;
	ret = malloc(sizeof(char *) * (idx + 1));
	if (ret == FALSE)
		return (FALSE);
	idx = 0;
	while (arr[idx])
	{
		ret[idx] = (char *)malloc(sizeof(char) * (ft_strlen(arr[idx]) + 1));
		if (ret[idx] == 0)
			return (clean_dchar(ret, idx));
		ft_strncpy(ret[idx], arr[idx], ft_strlen(arr[idx]));
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}

int	index_of(const char *key, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
	{
		j = -1;
		while (key[++j])
			if (env[i][j] != key[j])
				break ;
		if (env[i][j] == '=')
			return (i);
	}
	return (i);
}

char	*pointer_of(const char *key, char **env)
{
	int	index;

	index = index_of(key, env);
	return (env[index]);
}
