#include "minishell.h"

char	**copy_env(char **env)
{
	char	**ret;
	int		len;
	int		i;

	len = 0;
	while (env[len])
		len++;
	ret = malloc(sizeof(char *) * (len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < len)
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
			return (i)
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

	i = 0;
	while (g_val.env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (new_env == 0)
		reutrn (-1);
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
