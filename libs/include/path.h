#ifndef PATH_H
#define PATH_H

typedef struct s_path	t_path;

struct s_path
{
	t_path	*par_dir;
	t_path	*sub_dir;
	char	*path;
};

void parsetest(t_path *test);
t_path	*ft_path_parse(char *all_path);
void	ft_path_add(t_path **main, t_path *new);
t_path	*ft_path_frag(char *path);
char	**ft_split(char const *s, char c);
#endif