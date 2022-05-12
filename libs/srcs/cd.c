#include "../../inc/structure.h"
#include "../../inc/minishell.h"
#include <unistd.h>
#include <errno.h>

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

void	*clean_dchar(char **dchar, int cnt)
{
	int	i;

	if (dchar)
	{
		i = 0;
		while (i < cnt)
		{
			free(dchar[i]);
			i++;
		}
		free(dchar);
	}
	return (0);
}

void	*clean_elem(t_elem *elems, int cnt)
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

int cd(char *path)
{
	int ret;

	ret = chdir(path);
	printf("Return Code : %d\n", EFAULT);
	if (ret == EACCES)
		printf("Permission Denied\n");
	if (ret == -1)
		printf("Wrong Path\n");
	if (!ret)
	{
		// Modify $PWD
		//remove_env("PWD");
		//put_env("PWD");
		return (TRUE);
	}
	return (FALSE);
}