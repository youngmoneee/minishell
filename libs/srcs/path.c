#include "../include/path.h"
#include <stdlib.h>
#include <stdio.h>

static int	slen(const char *s)
{
	int idx = 0;

	while (s[idx])
		idx++;
	return (idx);
}

static void	ft_strncpy(char *dst, const char *src, int len)
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

static int	ft_issep(char c1, char c2)
{
	if (c1 == c2 || c1 == '\0')
		return (1);
	return (0);
}

static void	ft_catcat(char *dst, char *src, char c)
{
	size_t		idx;

	idx = 0;
	while (!ft_issep(src[idx], c) && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
}

static size_t	ft_cntsep(char *s, char c)
{
	size_t		cnt;
	size_t		idx;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (!ft_issep(s[idx], c) && ft_issep(s[idx + 1], c))
			cnt++;
		idx++;
	}
	return (cnt);
}

static void	ft_sep(char **ret, char *s, char c)
{
	size_t		size;
	size_t		curr;

	curr = 0;
	while (*s)
	{
		if (ft_issep(*s, c))
			s++;
		else
		{
			size = 0;
			while (!ft_issep(s[size], c) && s[size])
				size++;
			ret[curr] = (char *)malloc(sizeof(char) * size + 1);
			if (!ret[curr])
			{
				while (curr >= 0)
					free(ret[curr--]);
				return ;
			}
			ft_catcat(ret[curr++], s, c);
			s += size;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		size;

	if (!s)
		return ((void *)0);
	size = ft_cntsep((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (0);
	ft_sep(split, (char *)s, c);
	split[size] = 0;
	return (split);
}

t_path	*ft_path_frag(char *path)
{
	t_path	*new;
	int 	size;

	new = (t_path *)malloc(sizeof(t_path));
	size = slen(path);
	if (!new)
		return ((void *)0);
	new->path = (char *)malloc(sizeof(char) * (size + 1));
	ft_strncpy(new->path, path, size);
	new->par_dir = (void *)0;
	new->sub_dir = (void *)0;
	return (new);
}

void	ft_path_add(t_path **main, t_path *new)
{
	t_path	*curr;

	if (!*main)
	{
		*main = new;
		return ;
	}
		curr = *main;
		while (curr->sub_dir)
			curr = curr->sub_dir;
		curr->sub_dir = new;
		new->par_dir = curr;
}

t_path	*ft_path_parse(char *all_path)
{
	int 	idx;
	t_path	*main;
	t_path	*new;
	char	**paths;

	paths = ft_split(all_path, '/');
	idx = 0;
	main = 0;
	while(paths[idx])
	{
		new = ft_path_frag(paths[idx]);
		ft_path_add(&(main), new);
		free(paths[idx]);
		idx++;
	}
	free(paths);
	return (main);
}

void parsetest(t_path *test)
{
	printf("/%s", test->path);
	if (test->sub_dir)
	{
		parsetest(test->sub_dir);
	}
	else
		printf("\n");
}