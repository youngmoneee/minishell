#include "../../inc/structure.h"
# include <stdio.h>
# include <unistd.h>

t_bool	pwd(void)
{
	char	buf[BUFSIZE];
	void	*ret;

	ret = getcwd(buf, BUFSIZE);
	if (ret == NULL)
	{
		printf("Buffer Error\n");
		return (0);
	}
	printf("%s\n", buf);
	return (1);
}