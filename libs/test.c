#include "include/libs.h"
#include <stdio.h>
#include "../inc/structure.h"
#include <unistd.h>
t_glob	g_val;
int main(int argc, char **argv) {
	char *v[6] = {"qweqr", "zxc", "Hello world"};
	printf("=== Echo Test\n");
	echo(3, v);
	printf("\n");

	/*
	 * Path Parse Test
	 */
	/*
	printf("=== Path Parse Test\n");
	char *path = "/hello/my/name/is";
	char *path2 = "/test/path/t/e/s/t";
	t_path *test = ft_path_parse(path);
	t_path *test2 = ft_path_parse(path2);
	parsetest(test);
	parsetest(test2);
	printf("\n");
	*/
	/*
	 * Pwd Test
	 */
	printf("=== pwd Test\n");
	pwd();
	printf("\n");

	/*
	 * Cd Test
	 */
	printf("=== cd Test\n");
	char	before_path[BUFSIZE];
	char	after_path[BUFSIZE];
	char	scanner[BUFSIZE];
	printf("Before : %s\n", getcwd(before_path, BUFSIZE));
	printf("Input : ");
	scanf("%s", scanner);
	cd(scanner);
	printf("After : %s\n", getcwd(after_path, BUFSIZE));
	printf("\n");
	return 0;
}
